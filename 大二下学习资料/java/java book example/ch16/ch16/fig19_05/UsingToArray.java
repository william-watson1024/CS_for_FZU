// Fig. 19.5: UsingToArray.java
// Using method toArray.
import java.util.LinkedList;
import java.util.Arrays;

public class UsingToArray 
{
   // constructor creates LinkedList, adds elements and converts to array
   public UsingToArray()
   {
      String colors[] = { "black", "blue", "yellow" };

      LinkedList< String > links = 
         new LinkedList< String >( Arrays.asList( colors ) );

      links.addLast( "red" );   // add as last item
      links.add( "pink" );      // add to the end
      links.add( 3, "green" );  // add at 3rd index
      links.addFirst( "cyan" ); // add as first item      

      // get LinkedList elements as an array     
      colors = links.toArray( new String[ links.size() ] );

      System.out.println( "colors: " );

      for ( String color : colors )
         System.out.println( color );
   } // end UsingToArray constructor

   public static void main( String args[] )
   {
      new UsingToArray();
   } // end main 
} // end class UsingToArray


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
