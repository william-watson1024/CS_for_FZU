import java.awt.FlowLayout;   
import java.awt.event.ActionEvent;   
import java.awt.event.ActionListener;   
import javax.swing.JButton;   
import javax.swing.JFrame;   
import javax.swing.JProgressBar;   
import javax.swing.JTextField;   

public class SwingThreadTest1 extends JFrame {   
    private static final long serialVersionUID = 1L;   
    private static final String STR = "Completed : ";   
    private JProgressBar progressBar = new JProgressBar();   
    private JTextField text = new JTextField(10);   
    private JButton start = new JButton("Start");   
    private JButton end = new JButton("End");   
    private boolean flag = false;   
    private int count = 0;   
    
    public SwingThreadTest1() {
    	this.setLayout(new FlowLayout());   
        add(progressBar);   
        text.setEditable(false);   
        add(text);   
        add(start);   
        add(end);   
        start.addActionListener(
        		new ActionListener(){
        			public void actionPerformed(ActionEvent e) {   
        	            flag = true;//设置开始更新的标志   
        	            go();//开始工作   
        	        }   
        		}
        );   
        end.addActionListener(
        		new ActionListener(){
        			 public void actionPerformed(ActionEvent e) {   
        		            flag = false;//停止   
        		     } 
        		}
        );   
    }   
           
    private void go() {   
        while (count < 100) {   
            try {   
                Thread.sleep(100);//sleep（100）可看成要完成的某个耗时的工作   
            } catch (InterruptedException e) {   
                e.printStackTrace();   
            }   
            //更新进度条和输入框   
            if (flag) {   
                count++;   
                progressBar.setValue(count);   
                text.setText(STR + String.valueOf(count) + "%");   
            }   
        }   
    }   
    
    public static void main(String[] args) {   
        SwingThreadTest1 fg = new SwingThreadTest1();   
        fg.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
        fg.setSize(300, 100);   
        fg.setVisible(true);   
    }   
}
