import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class Texteditor extends JFrame implements ActionListener
{
	private JMenu filemenu= new JMenu("File");
	private JMenuItem fopen=new JMenuItem("Open");
	private JMenuItem exit=new JMenuItem("Exit");
	private JTextArea text=new JTextArea();
	private Container c;
	
	public Texteditor()
	{
		super("Text editor");
		filemenu.add(fopen);
		filemenu.add(exit);
		JMenuBar menu= new JMenuBar();
		menu.add(filemenu);
		setJMenuBar(menu);
		setLayout(new BorderLayout());
		add(text,BorderLayout.CENTER);
		fopen.addActionListener(this);
		exit.addActionListener(this);
		setSize(400,400);
		setVisible(true);	
	}
	
	public void readFile(String file)
	{
		text.setText("");
		try{
             //设置缓冲流并与文件流套接
			BufferedReader in= new BufferedReader(new FileReader(file));
			String line;
			
            //读文件，并将文件内容显示在文本区
			while((line=in.readLine())!= null)
			  text.append(line+"\n");
			
            //关闭缓冲流
			in.close();
			
            //设置光标的位置
			text.setCaretPosition(0);
		}catch(IOException ioe){
			System.err.println(ioe);
		}
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==exit)
		  System.exit(0);
		else if(e.getSource()==fopen)
		     {
                 //使用文件选择对话框
		     	JFileChooser fileChooser=new JFileChooser();
		     	
                 //设置让用户仅能通过该对话框选择文件
		     	fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		     	
                //弹出打开文件对话框
		     	int result=fileChooser.showOpenDialog(this);
		     	
                //如用户点击取消，则返回
		     	if(result==JFileChooser.CANCEL_OPTION)
		     	  return;
		     	
                //返回所选择的文件
		     	File filename=fileChooser.getSelectedFile();
		     	
		     	if(filename==null)
		     	  JOptionPane.showMessageDialog(this,"Invalid File Name","Invalid File Name",JOptionPane.ERROR_MESSAGE);
		     	else{
		     		readFile(filename.toString());
		     	}
		     }
		       
		       
	}
	
	public static void main(String arg[])
	{
		Texteditor te= new Texteditor();
	}
}
