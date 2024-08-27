// Fig. 19.3: CollectionTest.java
// Using the Collection interface.
import java.util.List;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class CollectionTest 
{
   private static final String[] colors = 
      { "MAGENTA", "RED", "WHITE", "BLUE", "CYAN" };
   private static final String[] removeColors = 
      { "RED", "WHITE", "BLUE" };

   // create ArrayList, add colors to it and manipulate it
   public CollectionTest()
   {
      List< String > list = new ArrayList< String >();      
      List< String > removeList = new ArrayList< String >();

      // add elements in colors array to list
      for ( String color : colors )
         list.add( color );       

      // add elements in removeColors to removeList
      for ( String color : removeColors )
         removeList.add( color ); 

      System.out.println( "ArrayList: " );

      // output list contents
      for ( int count = 0; count < list.size(); count++ )
         System.out.printf( "%s ", list.get( count ) );

      // remove colors contained in removeList
      removeColors( list, removeList );

      System.out.println( "\n\nArrayList after calling removeColors: " );

      // output list contents
      for ( String color : list )
         System.out.printf( "%s ", color );
   } // end CollectionTest constructor

   // remove colors specified in collection2 from collection1
   private void removeColors( 
      Collection< String > collection1, Collection< String > collection2 )
   {
      // get iterator
      Iterator< String > iterator = collection1.iterator(); 

      // loop while collection has items
      while ( iterator.hasNext() )         

         if ( collection2.contains( iterator.next() ) )
            iterator.remove(); // remove current Color
   } // end method removeColors

   public static void main( String args[] )
   {
      new CollectionTest();
   } // end main
} // end class CollectionTest

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
