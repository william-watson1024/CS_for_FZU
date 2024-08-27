import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue; 
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue; 
import java.util.concurrent.ThreadPoolExecutor; 
import java.util.concurrent.TimeUnit;

public class ExecutorsTest5 {
	private static final int NTHREDS=20;

	public static void main(String[] args){
		//BlockingQueue<Runnable> bqueue = new LinkedBlockingQueue<Runnable>();
		BlockingQueue<Runnable> bqueue = new ArrayBlockingQueue<Runnable>(10);
		ThreadPoolExecutor executor = new ThreadPoolExecutor(3,6,2,TimeUnit.MILLISECONDS, bqueue); 
        for (int i = 0; i < NTHREDS; i++) { 
            Runnable worker = new MyThread(); 
            executor.execute(worker); 
        } 
        executor.shutdown(); 
        while (!executor.isTerminated()) { } 
        System.out.println("Finished all threads"); 
    }

}
