import java.lang.Runnable;

public class MyThread implements Runnable { 
    public void run() { 
        System.out.println(Thread.currentThread().getName()); 
        try{
        	Thread.sleep(50);
        }
        catch(InterruptedException e){
        	e.printStackTrace();
        }
    } 
}
