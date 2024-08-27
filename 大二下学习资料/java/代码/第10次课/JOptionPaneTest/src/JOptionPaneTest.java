// Fig. 11.2: JOptionPaneTest.java
// Addition program that uses JOptionPane for input and output.
import javax.swing.JOptionPane; // program uses JOptionPane

public class JOptionPaneTest 
{
   public static void main( String args[] )
   {
      // obtain user input from JOptionPane input dialogs
      String firstNumber = 
         JOptionPane.showInputDialog( "Enter first integer" );
      String secondNumber =
          JOptionPane.showInputDialog( "Enter second integer" );

      // convert String inputs to int values for use in a calculation
      int number1 = Integer.parseInt( firstNumber ); 
      int number2 = Integer.parseInt( secondNumber );

      int sum = number1 + number2; // add numbers

      // display result in a JOptionPane message dialog
      JOptionPane.showMessageDialog( null, "The sum is " + sum, 
         "Sum of Two Integers", JOptionPane.PLAIN_MESSAGE );
      
      Object[] options = {"确定","取消","帮助"};
      int response=JOptionPane.showOptionDialog(null,"这是个选项对话框，用户可以选择自己的按钮的个数",  "选项对话框标题", JOptionPane.YES_OPTION, JOptionPane.QUESTION_MESSAGE,  null, options, options[0]);
      if(response==0)
      {
    	  JOptionPane.showMessageDialog(null,"You have chosen ok ","The Result is",JOptionPane.PLAIN_MESSAGE);
      }
      else if(response==1)
           {
    	      JOptionPane.showMessageDialog(null,"You have chosen cancle ","The Result is",JOptionPane.PLAIN_MESSAGE); 
    	   }
      else if(response==2) 
           { 
    	  JOptionPane.showMessageDialog(null,"You have chosen help ","The Result is",JOptionPane.PLAIN_MESSAGE);
    	   } 

      
      
      
   } // end method main
} // end class JOptionPaneTest


/**************************************************************************
 * (C) Copyright 1992-2009 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
