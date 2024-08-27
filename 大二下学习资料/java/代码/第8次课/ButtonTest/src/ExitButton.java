import java.awt.event.*;
import javax.swing.*;

public class ExitButton extends JFrame implements ActionListener
{
	private JButton B_Exit;
	public ExitButton(String str)
	{
		super(str);
		
        //创建按钮对象
        B_Exit=new JButton(" Exit ");
        
        //将按钮加载到JFrame中
        add(B_Exit);  
        
        //为按钮加载监听器
        B_Exit.addActionListener(this);  
	}
	
	public void actionPerformed(ActionEvent e)
    {
        dispose();
    }
	
	public static void main(String args[])
	{
		ExitButton eb=new ExitButton("Exit Test");
		eb.setSize(400,300); 
		eb.setVisible(true); 
		
	}

}
