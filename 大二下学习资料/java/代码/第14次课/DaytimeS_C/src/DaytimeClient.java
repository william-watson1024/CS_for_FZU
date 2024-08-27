import java.net.*;
import java.io.*;
public class DaytimeClient {
	public static void main(String[] args) {
		String hostname;
		if (args.length > 0) {
			hostname = args[0];
		}
		else {
			//此地址为获取精确时间的地址
			hostname = "localhost";
		}
		try {
          //获得套接字
			Socket theSocket = new Socket(hostname, 13); 
         
		  //得到输入流
			InputStream timeStream = theSocket.getInputStream( ); 
			StringBuffer time = new StringBuffer( );
			int c;
			while ((c = timeStream.read( )) != -1) 
				time.append((char) c);
         
		  //得到时间信息
			String timeString = time.toString().trim( ); 
			System.out.println("It is " + timeString + " at " + hostname);
			timeStream.close();
			theSocket.close();
		}
		catch (UnknownHostException e) {
			System.err.println(e);
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}