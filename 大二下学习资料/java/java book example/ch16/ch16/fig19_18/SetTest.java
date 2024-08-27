// Fig. 19.18: SetTest.java
// Using a HashSet to remove duplicates.
import java.util.List;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.Collection;

public class SetTest 
{
   private static final String colors[] = { "red", "white", "blue",
      "green", "gray", "orange", "tan", "white", "cyan",
      "peach", "gray", "orange" };
                  
   // create and output ArrayList
   public SetTest()
   {
      List< String > list = Arrays.asList( colors );
      System.out.printf( "ArrayList: %s\n", list );
      printNonDuplicates( list );
   } // end SetTest constructor

   // create set from array to eliminate duplicates
   private void printNonDuplicates( Collection< String > collection )
   {
      // create a HashSet 
      Set< String > set = new HashSet< String >( collection );   

      System.out.println( "\nNonduplicates are: " );

      for ( String s : set )
         System.out.printf( "%s ", s );

      System.out.println();
   } // end method printNonDuplicates

   public static void main( String args[] )
   {
      new SetTest();
   } // end main 
} // end class SetTest


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
