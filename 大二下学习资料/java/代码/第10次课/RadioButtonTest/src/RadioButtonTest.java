// Fig. 11.20: RadioButtonTest.java
// Testing RadioButtonFrame.

import java.awt.Toolkit;

import javax.swing.JFrame;

public class RadioButtonTest  
{
   public static void main( String args[] )
   {
      RadioButtonFrame radioButtonFrame = new RadioButtonFrame();
      
      radioButtonFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      radioButtonFrame.setSize( 300, 100 ); // set frame size
      radioButtonFrame.setVisible( true ); // display frame
      double width = Toolkit.getDefaultToolkit().getScreenSize().getWidth();
      double height = Toolkit.getDefaultToolkit().getScreenSize().getHeight();
      radioButtonFrame.setLocation( (int) (width - radioButtonFrame.getWidth()) / 2,(int) (height - radioButtonFrame.getHeight()) / 2);
      
   } // end main
} // end class RadioButtonTest 

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
