import java.awt.*;
import java.awt.CardLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.swing.JButton;


public class CardLayoutdemo extends JFrame implements ActionListener{

   JButton nextbutton,preButton;

   JPanel cardPanel=new JPanel();

   JPanel controlpaPanel=new JPanel();

        //定义卡片布局对象

   CardLayout card=new CardLayout();

       
        public CardLayoutdemo() {

                  super("卡片布局管理器");

                  



                  //设置cardPanel面板对象为卡片布局

                  cardPanel.setLayout(card);    



                  //循环，在cardPanel面板对象中添加4个按钮

                  //因为cardPanel面板对象为卡片布局，因此初始时显示最先添加的组件

                  for (int i = 0; i< 4; i++) {

                           //面板中添加的每个按钮对应设置一个卡片名

                           cardPanel.add(new JButton("按钮"+i));

                  }


                //实例化按钮对象

                  nextbutton=new JButton("下一张卡片");

                  preButton=new JButton("上一张卡片");



                  //为按钮对象注册监听器

                  nextbutton.addActionListener(this);

                  preButton.addActionListener(this);
                  
                  
                  controlpaPanel.add(preButton);

                  controlpaPanel.add(nextbutton);
                  
                  //定义容器对象为当前窗体容器对象

                  Container container=getContentPane();


                //将 cardPanel面板放置在窗口边界布局的中间，窗口默认为边界布局

                  container.add(cardPanel,BorderLayout.CENTER);

                  // 将controlpaPanel面板放置在窗口边界布局的南边，

                  container.add(controlpaPanel,BorderLayout.SOUTH);
                  
                  setSize(400,200);

                  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                  setLocationRelativeTo(null);

                  setVisible(true);
    }
        
        //实现按钮的监听触发时的处理

        public void actionPerformed(ActionEvent e){

                  //如果用户单击nextbutton，执行的语句

                  if (e.getSource()==nextbutton){

                           //切换cardPanel面板中当前组件之后的一个组件

                           //若当前组件为最后添加的组件，则显示第一个组件，即卡片组件显示是循环的。

                           card.next(cardPanel);     

                  }

                  if (e.getSource()==preButton){

                           //切换cardPanel面板中当前组件之前的一个组件

                           //若当前组件为第一个添加的组件，则显示最后一个组件，即卡片组件显示是循环的。

                           card.previous(cardPanel);

                  }

        }
        
        public static void main(String[] args) {

        	CardLayoutdemo testCardLayout=new CardLayoutdemo();

           

  }
}