import java.util.Random;

class MyThread extends Thread{
	private int sleepTime;
	private static Random generator=new Random();
	public MyThread(String n){
		super(n);
		} //n：线程名称
    public void run(){
	    for(int i=0;i<5;i++){
  	 	    // 睡眠一段随机时间
  	 	    try{
  	 	    	sleepTime=generator.nextInt(1000);
  	 	    	Thread.sleep(sleepTime);
  	 	    }catch (InterruptedException e) 
                     {e.printStackTrace();	}        
		    //显示本线程名称
		    System.out.print(getName()+"    "); 	
	    }  
	}
}

public class MultiThreadExample{
	public static void main(String []args){
		new MyThread("A").start(); //启动线程A
		new MyThread("B").start(); //启动线程B	
	}
}

