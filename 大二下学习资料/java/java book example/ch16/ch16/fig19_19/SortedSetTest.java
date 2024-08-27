// Fig. 19.19: SortedSetTest.java
// Using TreeSet and SortedSet.
import java.util.Arrays;
import java.util.SortedSet;
import java.util.TreeSet;

public class SortedSetTest 
{
   private static final String names[] = { "yellow", "green",
       "black", "tan", "grey", "white", "orange", "red", "green" };
   
   // create a sorted set with TreeSet, then manipulate it
   public SortedSetTest()
   {
      // create TreeSet
      SortedSet< String > tree = 
         new TreeSet< String >( Arrays.asList( names ) );

      System.out.println( "sorted set: " );
      printSet( tree ); // output contents of tree

      // get headSet based on "orange"
      System.out.print( "\nheadSet (\"orange\"):  " );
      printSet( tree.headSet( "orange" ) );

      // get tailSet based upon "orange"
      System.out.print( "tailSet (\"orange\"):  " );
      printSet( tree.tailSet( "orange" ) );

      // get first and last elements
      System.out.printf( "first: %s\n", tree.first() );
      System.out.printf( "last : %s\n", tree.last() );
   } // end SortedSetTest constructor

   // output set
   private void printSet( SortedSet< String > set )
   {
      for ( String s : set )
         System.out.print( s + " " );

      System.out.println();
   } // end method printSet

   public static void main( String args[] )
   {
      new SortedSetTest();
   } // end main
} // end class SortedSetTest

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
