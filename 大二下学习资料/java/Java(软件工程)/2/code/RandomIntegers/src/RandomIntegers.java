// Fig. 6.6: RandomIntegers.java
// Shifted and scaled random integers.
import java.util.Random; // program uses class Random

public class RandomIntegers 
{
   public static void main( String args[] )
   {      
      Random randomNumbers = new Random(); // random number generator
      int face; // stores each random integer generated

      // loop 20 times
      for ( int counter = 1; counter <= 20; counter++ ) 
      {
         // pick random integer from 1 to 6
         face = 1 + randomNumbers.nextInt( 6 );

         System.out.printf( "%d  ", face ); // display generated value
         
         // if counter is divisible by 5, start a new line of output
         if ( counter % 5 == 0 )
            System.out.println();
      } // end for
   } // end main
} // end class RandomIntegers


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
