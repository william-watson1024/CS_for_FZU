// Fig. 19.16: TicTacToeClientTest.java
// Tests the TicTacToeClient class.
import javax.swing.JFrame;

public class TicTacToeClientTest
{
   public static void main( String args[] )
   {
      TicTacToeClient application; // declare client application

      // if no command line args
      if ( args.length == 0 )
         application = new TicTacToeClient( "127.0.0.1" ); // localhost
      else
         application = new TicTacToeClient( args[ 0 ] ); // use args

      application.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
   } // end main
} // end class TicTacToeClientTest

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
