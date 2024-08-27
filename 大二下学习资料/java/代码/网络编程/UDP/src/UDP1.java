import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDP1 {
    public static void main(String []args)throws Exception{
        DatagramSocket ds=new DatagramSocket(8888);
        byte[] data =new byte[200];
        DatagramPacket packet=new DatagramPacket(data, data.length);
        while (true) {
            ds.receive(packet);
            System.out.println(new String(data));
        }
    }
}

