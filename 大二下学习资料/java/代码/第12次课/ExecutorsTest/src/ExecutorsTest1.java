import java.util.concurrent.ExecutorService; 
import java.util.concurrent.Executors;

public class ExecutorsTest1{
	private static final int NTHREDS=10;
	public static void main(String[] args){
		ExecutorService executor = Executors.newFixedThreadPool(NTHREDS); 
        for (int i = 0; i < 15; i++) { 
            Runnable worker = new MyThread(); 
            executor.execute(worker); 
        } 
        executor.shutdown(); 
        while (!executor.isTerminated()) { } 
        System.out.println("Finished all threads"); 
        
    }
}
