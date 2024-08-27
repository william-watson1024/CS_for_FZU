// Fig. 19.9: Sort2.java
// Using a Comparator object with algorithm sort.
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class Sort2 
{
   private static final String suits[] = 
      { "Hearts", "Diamonds", "Clubs", "Spades" };

   // output List elements
   public void printElements()
   {
      List< String > list = Arrays.asList( suits ); // create List

      // output List elements
      System.out.printf( "Unsorted array elements:\n%s\n", list );

      // sort in descending order using a comparator
      Collections.sort( list, Collections.reverseOrder() ); 

      // output List elements
      System.out.printf( "Sorted list elements:\n%s\n", list );
   } // end method printElements
 
   public static void main( String args[] )
   {
      Sort2 sort2 = new Sort2();
      sort2.printElements();
   } // end main
} // end class Sort2


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
