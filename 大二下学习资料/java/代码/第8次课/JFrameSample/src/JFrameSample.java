import javax.swing.*;

public class JFrameSample extends JFrame{
	
	JButton b_exit;
	
    JFrameSample(String str)
    {
        super(str);
        setSize(400,300);       //设置窗口大小
        //创建按钮对象
        b_exit=new JButton(" Exit ");
        add(b_exit);    
    }

    public static void main(String args[])
    {
        //创建窗体对象并设置窗体标题
        JFrame frame = new JFrameSample("sample frame");
        frame.setVisible(true);    //显示窗体
    }

}
