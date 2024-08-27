import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;

public class ConcurrentCalculator {
	private ExecutorService exec;
	private int cpuCoreNumber;
	private List<Future<Long>> tasks = new ArrayList<Future<Long>>();
	
	//内部类
	class SumCalculator implements Callable<Long >{
		//线程中用来计算的部分，相当于run（）方法
		private int[] numbers;
		private int start;
		private int end;

		public SumCalculator(final int[] numbers, int start, int end){
			this.numbers = numbers;
			this.start = start;
			this.end = end;
		}
		
		public Long call() throws Exception {
			Long sum = 0l;
			for (int i = start; i < end; i++) {
				sum += numbers[i];
			}
			return sum;
		}
	}
	
	//构造函数
	public ConcurrentCalculator() {
		cpuCoreNumber = Runtime.getRuntime().availableProcessors();
		System.out.println(cpuCoreNumber);
		exec = Executors.newFixedThreadPool(cpuCoreNumber);
	}
	
	public Long sum(final int[] numbers) {
		// 根据CPU核心个数拆分任务，创建FutureTask并提交到Executor
		for (int i = 0; i < cpuCoreNumber; i++) {
			int increment = numbers.length / cpuCoreNumber+1;
			
			int start = increment * i;
			int end = increment * i + increment;
			if (end > numbers.length)
				end = numbers.length;
			SumCalculator subCalc = new SumCalculator(numbers, start, end);
			
			//线程：使用FutureTask包装callable对象成为Runnable对象
			FutureTask<Long> task = new FutureTask<Long>(subCalc); 
			
			tasks.add(task);
			if (!exec.isShutdown()) 
				exec.submit(task); //执行线程
			
		}
		return getResult();
	}
	
	public Long getResult() {
		Long result = 0l;
		for (Future<Long> task : tasks) {
			try {
				// 如果计算未完成则阻塞
				Long subSum = task.get(); //得到每个线程的计算结果
				result += subSum;
				} 
			catch (InterruptedException e) {
				e.printStackTrace();
			} 
			catch (ExecutionException e) {
				e.printStackTrace();
			}
		}
		return result;
	}

	public void close() {
		exec.shutdown();
	}

	public static void main(String[] args){
		int[] numbers = new int[] { 1, 2, 3,4,5,6,7,8};
		ConcurrentCalculator calc = new ConcurrentCalculator();
		Long sum = calc.sum(numbers);
		System.out.printf("The result is %d",sum);
		calc.close(); 
	}
}