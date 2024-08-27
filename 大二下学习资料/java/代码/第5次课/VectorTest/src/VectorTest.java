// Fig. 19.6: VectorTest.java
// Using the Vector class.
import java.util.Vector;
import java.util.NoSuchElementException;

public class VectorTest 
{
   private static final String colors[] = { "red", "white", "blue" };

   public VectorTest()
   {
      Vector< String > vector = new Vector< String >();
      printVector( vector ); // print vector

      // add elements to the vector
      for ( String color : colors )
         vector.add( color );   

      printVector( vector ); // print vector
      
      // output the first and last elements
      try 
      {
         System.out.printf( "First element: %s\n", vector.firstElement());
         System.out.printf( "Last element: %s\n", vector.lastElement() );
      } // end try
      // catch exception if vector is empty
      catch ( NoSuchElementException exception ) 
      {
         exception.printStackTrace();
      } // end catch
      
      // does vector contain "red"?
      if ( vector.contains( "red" ) )
         System.out.printf( "\n\"red\" found at index %d\n\n", 
            vector.indexOf( "red" ) );
      else
         System.out.println( "\n\"red\" not found\n" );
      
      vector.remove( "red" ); // remove the string "red"
      System.out.println( "\"red\" has been removed" );
      printVector( vector ); // print vector
      
      // does vector contain "red" after remove operation?
      if ( vector.contains( "red" ) )
         System.out.printf( 
            "\"red\" found at index %d\n", vector.indexOf( "red" ) );
      else
         System.out.println( "\"red\" not found" );
      
      // print the size and capacity of vector
      System.out.printf( "\nSize: %d\nCapacity: %d\n", vector.size(), 
         vector.capacity() );
   } // end VectorTest convcvxcxv structor
   
   private void printVector( Vector< String > vectorToOutput )
   {
      if ( vectorToOutput.isEmpty() ) 
         System.out.print( "vector is empty" ); // vectorToOutput is empty
      else  // iterate through the elements
      { 
         System.out.print( "vector contains: " );      

         // output elements
         for ( String element : vectorToOutput )
            System.out.printf( "%s ", element );
      } // end else
      
      System.out.println( "\n" ); 
   } // end method printVector

   public static void main( String args[] )
   {
      new VectorTest(); // create object and call its constructor
   } // end main
} // end class VectorTest

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
