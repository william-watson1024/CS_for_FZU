import java.net.*; 
import java.io.*; 

public class DaytimeServer 
{ 
	public static final int SERVICE_PORT = 13; 
	public static void main(String args[]) 
	{ 
		try 
		{ 
			// 绑定到服务端口，给客户端授予访问TCP daytime服务的权限 
			ServerSocket server = new ServerSocket(SERVICE_PORT); 
			System.out.println ("Daytime service started"); 
			
			// 无限循环，接受客户端 
			while(true)
			{
				// 获取下一个TCP客户端 
				Socket nextClient = server.accept(); 
				
				// 显示连接细节 
				System.out.println ("Received request from " + 
					nextClient.getInetAddress() + ":" + nextClient.getPort() ); 
				
				// 不读取数据，只是向消息写信息 
				OutputStream out = nextClient.getOutputStream(); 
				PrintStream pout = new PrintStream (out); 
				
				// 把当前数据显示给用户 
				pout.print( new java.util.Date() ); 
				
				// 清除未发送的字节 
				out.flush(); 
				
				// 关闭流 
				out.close(); 
				
				// 关闭连接 
				nextClient.close(); 
			} 
		} 
		catch (BindException be) 
		{ 
			//打印错误信息
			System.err.println ("Service already running on port " + SERVICE_PORT ); 
		} 
		catch (IOException ioe) 
		{ 
			System.err.println ("I/O error - " + ioe); 
		} 
	} 
} 