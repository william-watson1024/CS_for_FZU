import java.io.*;
import java.net.*;
import java.util.Scanner;

// 客户端类
public class Client {
    public static void main(String[] argc) {
        try {
            // 创建一个Socket对象，连接到本地主机的8888端口
            Socket s = new Socket("localhost", 8888);
            InputStream is = s.getInputStream();
            // 获取Socket的输出流，用于向服务器发送数据
            OutputStream os = s.getOutputStream();
            // 使用PrintWriter包装输出流，以便更方便地写入文本
            PrintWriter writer = new PrintWriter(os);
            // 获取Socket的输入流，用于接收服务器的数据
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            // 创建Scanner对象，用于读取控制台输入
            Scanner sc = new Scanner(System.in);
            // 无限循环，持续读取用户输入并发送到服务器
            while (true) {
                String str = sc.next(); // 读取用户输入的一行文本
                if (str == null) { // 如果输入为null，退出循环
                    break;
                }
                writer.println(str); // 将用户输入写入输出流，并添加换行符
                writer.flush(); // 立即清空输出缓冲区，确保数据被发送
                System.out.println(br.readLine());
            }

            // 关闭资源
            writer.close();
            os.close();
            s.close();
        } catch (Exception e) {
            // 打印异常堆栈信息，便于调试
            e.printStackTrace();
        }
    }
}

