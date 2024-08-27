import java.net.*;
import java.io.*;
import java.util.Scanner;
// 服务端类
public class Server {
    public static void main(String[] argc) {
        try {
            // 创建ServerSocket对象，监听8888端口，等待客户端连接
            ServerSocket ss = new ServerSocket(8888);

            // 接受一个客户端的连接请求
            Socket s = ss.accept();
            OutputStream os = s.getOutputStream();
            // 获取Socket的输入流，用于读取客户端发来的数据
            InputStream is = s.getInputStream();
            // 获取Socket的输出流，用于向客户端发送数据
            PrintWriter writer = new PrintWriter(os);
            // 使用BufferedReader包装输入流，以便按行读取文本
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            // 创建Scanner对象，用于读取控制台输入（实际上这里应直接提供响应，示例中可能有误）
            Scanner sc = new Scanner(System.in);
            // 无限循环，持续读取客户端发送的消息并回应
            while (true) {
                String msg = br.readLine(); // 读取一行客户端发送的消息
                if (msg == null) { // 如果消息为null，表示连接关闭，退出循环
                    break;
                }
                // 这里实际上应该直接发送处理后的消息或固定响应给客户端，而不是读取控制台输入
                // 但为了与示例代码保持一致，保留了读取控制台的逻辑
                writer.println(sc.next()); // 发送从控制台读取的一行文本作为响应
                writer.flush(); // 清空输出缓冲区，确保数据被发送
            }

            // 关闭资源
            writer.close();
            is.close();
            s.close();
            ss.close();

        } catch (Exception e) {
            // 打印异常堆栈信息，便于调试
            e.printStackTrace();
        }
    }
}