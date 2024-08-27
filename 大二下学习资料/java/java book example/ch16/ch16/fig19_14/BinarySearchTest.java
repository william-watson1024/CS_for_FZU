// Fig. 19.14: BinarySearchTest.java
// Using algorithm binarySearch.
import java.util.List;
import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;

public class BinarySearchTest 
{
   private static final String colors[] = { "red", "white",  
      "blue", "black", "yellow", "purple", "tan", "pink" };
   private List< String > list; // ArrayList reference

   // create, sort and output list 
   public BinarySearchTest()
   {
      list = new ArrayList< String >( Arrays.asList( colors ) );  
      Collections.sort( list ); // sort the ArrayList
      System.out.printf( "Sorted ArrayList: %s\n", list );
   } // end BinarySearchTest constructor

   // search list for various values
   private void search()
   {
      printSearchResults( colors[ 3 ] ); // first item
      printSearchResults( colors[ 0 ] ); // middle item
      printSearchResults( colors[ 7 ] ); // last item
      printSearchResults( "aqua" ); // below lowest
      printSearchResults( "gray" ); // does not exist
      printSearchResults( "teal" ); // does not exist
   } // end method search

   // helper method to perform searches
   private void printSearchResults( String key )
   {
      int result = 0;

      System.out.printf( "\nSearching for: %s\n", key );
      result = Collections.binarySearch( list, key );
      
      if ( result >= 0 )
         System.out.printf( "Found at index %d\n", result );
      else
         System.out.printf( "Not Found (%d)\n",result );
   } // end method printSearchResults

   public static void main( String args[] )
   {
      BinarySearchTest binarySearchTest = new BinarySearchTest();
      binarySearchTest.search();
   } // end main     
} // end class BinarySearchTest

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
