import java.util.concurrent.ExecutorService; 
import java.util.concurrent.Executors;

public class ExecutorsTest3{
	private static final int NTHREDS=15;
	public static void main(String[] args){
		ExecutorService executor = Executors.newCachedThreadPool(); 
        for (int i = 0; i < NTHREDS; i++) { 
            Runnable worker = new MyThread(); 
            executor.execute(worker); 
        } 
        executor.shutdown(); 
        while (!executor.isTerminated()) { } 
        System.out.println("Finished all threads"); 
    }
}

