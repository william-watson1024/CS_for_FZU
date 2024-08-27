import java.util.concurrent.Executors; 
import java.util.concurrent.ScheduledExecutorService; 
import java.util.concurrent.TimeUnit; 


public class ExecutorsTest4{
	
	public static void main(String[] args){
		ScheduledExecutorService executor = Executors.newScheduledThreadPool(2);
		Runnable w1 = new MyThread();
		Runnable w2 = new MyThread();
		Runnable w3 = new MyThread();
		Runnable w4 = new MyThread();
		Runnable w5 = new MyThread();
		executor.execute(w1); 
		executor.execute(w2); 
		executor.execute(w3); 
		
		// π”√—”≥Ÿ÷¥––
		executor.schedule(w4, 1500, TimeUnit.MILLISECONDS); 
		executor.schedule(w5, 1500, TimeUnit.MILLISECONDS); 
        executor.shutdown(); 
        while (!executor.isTerminated()) { } 
        System.out.println("Finished all threads"); 
    }
}
