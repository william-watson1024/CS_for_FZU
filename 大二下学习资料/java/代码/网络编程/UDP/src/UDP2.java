import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class UDP2 {
    public static void main()throws Exception{
        DatagramSocket ds=new DatagramSocket();
        byte[] sendData;
        Scanner sc=new Scanner(System.in);
        while (true){
            String next=sc.next();
            sendData=new String(next).getBytes();
            InetAddress address=InetAddress.getLocalHost();
            DatagramPacket packet=new DatagramPacket(sendData,sendData.length,address,8888);
            ds.send(packet);
        }
    }
}
