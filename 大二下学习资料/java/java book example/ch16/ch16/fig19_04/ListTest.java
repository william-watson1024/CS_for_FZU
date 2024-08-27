// Fig. 19.4: ListTest.java
// Using LinkLists.
import java.util.List;
import java.util.LinkedList;
import java.util.ListIterator;

public class ListTest 
{
   private static final String colors[] = { "black", "yellow", 
      "green", "blue", "violet", "silver" };
   private static final String colors2[] = { "gold", "white", 
      "brown", "blue", "gray", "silver" };
                  
   // set up and manipulate LinkedList objects
   public ListTest()
   {
      List< String > list1 = new LinkedList< String >(); 
      List< String > list2 = new LinkedList< String >();

      // add elements to list link
      for ( String color : colors )
         list1.add( color );

      // add elements to list link2
      for ( String color : colors2 )
         list2.add( color );

      list1.addAll( list2 ); // concatenate lists
      list2 = null; // release resources
      printList( list1 ); // print list1 elements

      convertToUppercaseStrings( list1 ); // convert to uppercase string
      printList( list1 ); // print list1 elements

      System.out.print( "\nDeleting elements 4 to 6..." );
      removeItems( list1, 4, 7 ); // remove items 4-7 from list
      printList( list1 ); // print list1 elements
      printReversedList( list1 ); // print list in reverse order
   } // end ListTest constructor

   // output List contents
   public void printList( List< String > list )
   {
      System.out.println( "\nlist: " );
   
      for ( String color : list )
         System.out.printf( "%s ", color );

      System.out.println();
   } // end method printList                                                   

   // locate String objects and convert to uppercase
   private void convertToUppercaseStrings( List< String > list )
   {
      ListIterator< String > iterator = list.listIterator();

      while ( iterator.hasNext() ) 
      {
         String color = iterator.next();  // get item
         iterator.set( color.toUpperCase() ); // convert to upper case
      } // end while
   } // end method convertToUppercaseStrings

   // obtain sublist and use clear method to delete sublist items
   private void removeItems( List< String > list, int start, int end )
   {
      list.subList( start, end ).clear();  // remove items
   } // end method removeItems

   // print reversed list
   private void printReversedList( List< String > list )
   {
      ListIterator< String > iterator = list.listIterator( list.size() );

      System.out.println( "\nReversed List:" );

      // print list in reverse order
      while ( iterator.hasPrevious() ) 
         System.out.printf( "%s ", iterator.previous() ); 
   } // end method printReversedList
   
   public static void main( String args[] )
   {
      new ListTest();
   } // end main                                    
} // end class ListTest


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
