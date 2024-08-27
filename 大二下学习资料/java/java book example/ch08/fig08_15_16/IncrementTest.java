// Fig. 8.16: IncrementTest.java
// final variable initialized with a constructor argument.

public class IncrementTest 
{
   public static void main( String args[] )
   {
      Increment value = new Increment( 5 );

      System.out.printf( "Before incrementing: %s\n\n", value );

      for ( int i = 1; i <= 3; i++ ) 
      {
         value.addIncrementToTotal();
         System.out.printf( "After increment %d: %s\n", i, value );
      } // end for
   } // end main
} // end class IncrementTest

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
