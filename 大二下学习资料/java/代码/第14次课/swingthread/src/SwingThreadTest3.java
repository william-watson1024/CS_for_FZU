import java.awt.FlowLayout;   
import java.awt.event.ActionEvent;   
import java.awt.event.ActionListener;   
import javax.swing.JButton;   
import javax.swing.JFrame;   
import javax.swing.JProgressBar;   
import javax.swing.JTextField;   
import javax.swing.SwingUtilities;   

public class SwingThreadTest3 extends JFrame {   
    private static final long serialVersionUID = 1L;   
    private static final String STR = "Completed : ";   
    private JProgressBar progressBar = new JProgressBar();   
    private JTextField text = new JTextField(10);   
    private JButton start = new JButton("Start");   
    private JButton end = new JButton("End");   
    private boolean flag = false;   
    private int count = 0;   
       
    private GoThread t = null;   
       
    private Runnable run = null;//更新组件的线程   
    
    public SwingThreadTest3() {   
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
    
    class GoThread extends Thread{   
        public void run() {   
            //do something   
            go(); 
        	
        }   
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
                SwingUtilities.invokeLater(
                		new Runnable(){//实例化更新组件的线程   
                            public void run() {   
                                progressBar.setValue(count);   
                                text.setText(STR + String.valueOf(count) + "%");   
                            }   
                        }
                );//将对象排到事件派发线程的队列中   
            }   
        }   
    }   
      
    public static void main(String[] args) {   
        SwingThreadTest3 fg = new SwingThreadTest3();   
        fg.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
        fg.setSize(300, 100);   
        fg.setVisible(true);   
    }   
}
