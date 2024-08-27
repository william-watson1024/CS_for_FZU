import java.awt.FlowLayout;   
import java.awt.event.ActionEvent;   
import java.awt.event.ActionListener;   
import javax.swing.JButton;   
import javax.swing.JFrame;   
import javax.swing.JProgressBar;   
import javax.swing.JTextField;   

public class SwingThreadTest2 extends JFrame {
	private static final long serialVersionUID = 1L;   
    private static final String STR = "Completed : ";   
    private JProgressBar progressBar = new JProgressBar();   
    private JTextField text = new JTextField(10);   
    private JButton start = new JButton("Start");   
    private JButton end = new JButton("End");   
    private boolean flag = false;   
    private int count = 0;   
       
    GoThread t = null;   
    public SwingThreadTest2() {   
        this.setLayout(new FlowLayout());   
        add(progressBar);   
        text.setEditable(false);   
        add(text);   
        add(start);   
        add(end);   
        
        start.addActionListener(
        		new ActionListener(){
        			public void actionPerformed(ActionEvent e) {   
        	            flag = true;   
        	            if(t == null){   
        	                t = new GoThread();   
        	                t.start();   
        	            }   
        	        }  
        		}
        );  
        
        end.addActionListener(
        		new ActionListener(){
        			public void actionPerformed(ActionEvent e) {   
        	            flag = false;   
        	        } 
        		}
        		);   
    }   
    
    private void go() {   
        while (count < 100) {   
            try {   
                Thread.sleep(100);   
            } catch (InterruptedException e) {   
                e.printStackTrace();   
            }   
            if (flag) {   
                count++;   
                System.out.println(count);   
                progressBar.setValue(count);   
                text.setText(STR + String.valueOf(count) + "%");   
            }   
        }   
    }   
    
    //执行复杂工作，然后更新组件的线程   
    class GoThread extends Thread{   
        public void run() {   
            //do something   
            go();   
        }   
    }   
    
    public static void main(String[] args) {   
        SwingThreadTest2 fg = new SwingThreadTest2();   
        fg.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
        fg.setSize(300, 100);   
        fg.setVisible(true);   
    }   
}
