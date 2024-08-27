import java.io.*; 
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class NumberRangeException extends Exception
{
	public NumberRangeException(String msg)
    {  super(msg);  }
}

public class Exception2 extends JFrame
{
	private JTextField textField1,textField2;
	private FlowLayout fLayout;
	private JButton btn;
	private JLabel l;
	int i;
	
	public int CalcAnswer() throws NumberRangeException
    {
		int int1, int2;    
        int answer = -1;
        String str1 = textField1.getText();
        String str2 = textField2.getText();
        
    
            int1 = Integer.parseInt(str1);
            int2 = Integer.parseInt(str2);
            //当数据不复合范围时抛出异常。
            if ((int1 < 10) || (int1 > 20) ||(int2 < 10) || (int2 > 20))
            {
        	    NumberRangeException e = new NumberRangeException("numbers not within the specified range.");
                throw e;
            }
            
            answer=int1+int2;
   
        return answer;
    }
	
	public Exception2(String s)
	{
		super(s);
		textField1=new JTextField(10);
		textField2=new JTextField(10);
		btn=new JButton("add");
		l=new JLabel("result");
		fLayout = new FlowLayout();
		setLayout(fLayout);
		add(textField1);
		add(textField2);	
		add(btn);
		add(l);
		btn.addActionListener(
				new ActionListener()
				{
					public void actionPerformed(ActionEvent e)
					{
						try
						{
							i=CalcAnswer();
							l.setText(Integer.toString(i));		             
						}
						catch(NumberRangeException ex)
						{
							System.out.println(ex.toString()) ;
						}
					}
				});
		setSize(400,100);
		setVisible(true);		
	}
    
	public static void main(String arg[])
	{
		Exception2 ec= new Exception2("try");
	}
}
