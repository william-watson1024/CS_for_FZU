// Fig. 19.13: Algorithms1.java
// Using algorithms reverse, fill, copy, min and max.
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class Algorithms1 
{
   private Character[] letters = { 'P', 'C', 'M' };
   private Character[] lettersCopy;
   private List< Character > list;
   private List< Character > copyList;

   // create a List and manipulate it with methods from Collections
   public Algorithms1()
   {
      list = Arrays.asList( letters ); // get List
      lettersCopy = new Character[ 3 ]; 
      copyList = Arrays.asList( lettersCopy ); // list view of lettersCopy

      System.out.println( "Initial list: " );
      output( list );

      Collections.reverse( list ); // reverse order
      System.out.println( "\nAfter calling reverse: " );
      output( list );

      Collections.copy( copyList, list ); // copy List
      System.out.println( "\nAfter copying: " );
      output( copyList );

      Collections.fill( list, 'R' ); // fill list with Rs
      System.out.println( "\nAfter calling fill: " );
      output( list );
   } // end Algorithms1 constructor

   // output List information
   private void output( List< Character > listRef )
   {
      System.out.print( "The list is: " );

      for ( Character element : listRef )
         System.out.printf( "%s ", element );

      System.out.printf( "\nMax: %s", Collections.max( listRef ) );
      System.out.printf( "  Min: %s\n", Collections.min( listRef ) );
   } // end method output

   public static void main( String args[] )
   {
      new Algorithms1();
   } // end main
} // end class Algorithms1

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
