import java.util.concurrent.ExecutorService; 
import java.util.concurrent.Executors;

public class ExecutorsTest2{
	private static final int NTHREDS=10;
	public static void main(String[] args){
		ExecutorService executor = Executors.newSingleThreadExecutor();  
        for (int i = 0; i < NTHREDS; i++) { 
            Runnable worker = new MyThread(); 
            executor.execute(worker); 
        } 
        executor.shutdown(); 
        while (!executor.isTerminated()) { } 
        System.out.println("Finished all threads"); 
    }
}