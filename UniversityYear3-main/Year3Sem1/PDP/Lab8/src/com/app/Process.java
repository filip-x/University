package com.app;

import com.app.msg.StopMessage;
import com.app.msg.Message;
import com.app.msg.SubscribeMessage;
import com.app.msg.UpdateMessage;
import mpi.MPI;

public class Process implements Runnable{
    private final DSM dsm;

    public Process(DSM dsm) {
        this.dsm = dsm;
    }

    @Override
    public void run() {
        while (true) {
            System.out.println("Process with rank " + MPI.COMM_WORLD.Rank() + " waiting for a message...");
            Object[] messages = new Object[1];

            MPI.COMM_WORLD.Recv(messages, 0, 1, MPI.OBJECT, MPI.ANY_SOURCE, MPI.ANY_TAG);
            Message message = (Message) messages[0];

            if (message instanceof StopMessage){
                System.out.println("Process rank = " + MPI.COMM_WORLD.Rank() + " stopped listening");
                System.out.println("For process with rank " + MPI.COMM_WORLD.Rank() + " the DSM is :" + dsm.toString());
                return;
            }
            else if (message instanceof SubscribeMessage) {
                SubscribeMessage subscribeMessage = (SubscribeMessage) message;
                System.out.println("Subscribe notification: Process " + MPI.COMM_WORLD.Rank() + " received: Process " +
                        subscribeMessage.rank + " subscribed to " + subscribeMessage.var);
                dsm.syncSubscription(subscribeMessage.var, subscribeMessage.rank);
            }
            else if (message instanceof UpdateMessage) {
                UpdateMessage updateMessage = (UpdateMessage) message;
                System.out.println("Update notification: Process " + MPI.COMM_WORLD.Rank() + " received: " +
                        updateMessage.var + " = " + updateMessage.val);
                dsm.setVariable(updateMessage.var, updateMessage.val);
            }

            //System.out.println(dsm.toString());
        }
    }
}
