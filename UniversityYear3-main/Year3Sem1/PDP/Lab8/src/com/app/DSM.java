package com.app;

import com.app.msg.StopMessage;
import com.app.msg.Message;
import com.app.msg.SubscribeMessage;
import com.app.msg.UpdateMessage;
import mpi.MPI;

import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class DSM {

    public Map<String, Set<Integer>> variableSubscribers;
    public int a, b, c;
    public static final Lock lock = new ReentrantLock();

    public DSM() {
        a = 30;
        b = 31;
        c = 32;

        variableSubscribers = new ConcurrentHashMap<>();
        variableSubscribers.put("a", new HashSet<>());
        variableSubscribers.put("b", new HashSet<>());
        variableSubscribers.put("c", new HashSet<>());
    }

    public void updateVariable(String var, int value) {
        lock.lock();

        this.setVariable(var, value);
        Message message = new UpdateMessage(var, value);
        this.sendNotificationsToSubscribers(var, message);

        lock.unlock();
    }

    public void setVariable(String var, int value) {
        if (var.equals("a"))
            this.a = value;
        if (var.equals("b"))
            this.b = value;
        if (var.equals("c"))
            this.c = value;
    }

    public void compareAndExchange(String var, int oldValue, int newValue) {
        System.out.println("CompareAndExchange oldVal = " + oldValue + " newVal = " + newValue);
        if (var.equals("a") && this.a == oldValue) {
            updateVariable("a", newValue);
        }
        if (var.equals("b")&& this.b == oldValue) {
            updateVariable("b", newValue);
        }
        if (var.equals("c") && this.c == oldValue) {
            updateVariable("c", newValue);
        }
    }

    public void subscribeToVariable(String var) {
        // add the new process to the processes already added
        Set<Integer> subscribers = this.variableSubscribers.get(var);
        subscribers.add(MPI.COMM_WORLD.Rank());
        this.variableSubscribers.put(var, subscribers);

        this.sendNotificationsToAll(new SubscribeMessage(var, MPI.COMM_WORLD.Rank()));
    }

    public void syncSubscription(String var, int rank) {
        Set<Integer> subs = this.variableSubscribers.get(var);
        subs.add(rank);
        this.variableSubscribers.put(var, subs);
    }

    public void sendNotificationsToSubscribers(String var, Message message) {
        for (int i = 0; i < MPI.COMM_WORLD.Size(); i++) {
            if (MPI.COMM_WORLD.Rank() == i || !variableSubscribers.get(var).contains(i))
                continue;

            MPI.COMM_WORLD.Send(new Object[]{message}, 0, 1, MPI.OBJECT, i, 0);
        }
    }

    private void sendNotificationsToAll(Message message) {
        for (int i = 0; i < MPI.COMM_WORLD.Size(); i++) {
            if (MPI.COMM_WORLD.Rank() == i && !(message instanceof StopMessage))
                continue;
            MPI.COMM_WORLD.Send(new Object[]{message},0,1,MPI.OBJECT, i, 0);
        }
    }

    public void close() {
        this.sendNotificationsToAll(new StopMessage());
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("==\n");
        stringBuilder.append("Process ").append(MPI.COMM_WORLD.Rank()).append(": a = ").append(a).append(" b = ").append(b).append(" c = ").append(c).append("\n");
        stringBuilder.append("Subscribers: \n");
        for (String var : variableSubscribers.keySet()) {
            stringBuilder.append(var).append(" ").append(variableSubscribers.get(var).toString()).append("\n");
        }
        stringBuilder.append("==");
        return stringBuilder.toString();
    }
}