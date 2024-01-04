package app;


import lombok.Data;
import lombok.Setter;

import java.util.Random;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

@Data
public class Application {
    private Long scalarProductSum = 0L;
    private Integer computedScalarProduct = null;
    private Lock mutex = new ReentrantLock();
    private final Condition condition = mutex.newCondition();
    @Setter
    private boolean running = true;
    // v = 1i+ 5j && u = 2i+7j =>>>> uv = (1*2)i +(5*7)j = 2i +35j
    private class ProducerThread extends  Thread{
        private Integer computeRandomScalarProduct(){
            Random random  =new Random();
            int i1,i2,j1,j2;
            i1 = random.nextInt(1000);
            i2 = random.nextInt(1000);
            j1 = random.nextInt(1000);
            j2 = random.nextInt(1000);
            return i1*i2 + j1*j2;
        }
        public void run(){
            mutex.lock();
            try {
                int scalarProduct;
                while (running) {
                    scalarProduct = computeRandomScalarProduct();

                    while (computedScalarProduct != null) {
                        condition.await();
                    }
                    computedScalarProduct = scalarProduct;
                    System.out.println("Computed scalar product " +scalarProduct);
                    condition.signal();
                }
            } catch (RuntimeException | InterruptedException exception) {
                running = false;
                System.out.println("An exception has occured in Producer thread! "+ exception.getMessage());
                mutex.unlock();
            }
        }
    }
    private class ConsumerThread extends Thread {

        public void run() {
            mutex.lock();
            try {
                while (running) {

                    while (computedScalarProduct == null) {
                        condition.await();
                    }
                    scalarProductSum += computedScalarProduct;
                    computedScalarProduct = null;
                    System.out.println("The sum of scalar products is now:"+ scalarProductSum);
                    condition.signal();
                }
            } catch (RuntimeException | InterruptedException exception) {
                running = false;
                System.out.println("An exception has occurred in Consumer thread! " +exception.getMessage());

                mutex.unlock();
            }

        }
    }
    private void startThread(){
        Thread producerThread = new ProducerThread();
        producerThread.start();
        Thread consumerThread = new ConsumerThread();
        consumerThread.start();

    }

    public void start(){
        startThread();
    }
}
