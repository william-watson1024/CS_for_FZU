// Fig. 19.15: Algorithms2.java
// Using algorithms addAll, frequency and disjoint.
import java.util.List;
import java.util.Vector;
import java.util.Arrays;
import java.util.Collections;
//addAll,disjoint
public class Algorithms2 
{
   private String[] colors = { "red", "white", "yellow", "blue" };
   private List< String > list;
   private Vector< String > vector = new Vector< String >();
   
   // create List and Vector 
   // and manipulate them with methods from Collections
   public Algorithms2()
   {
      // initialize list and vector
      list = Arrays.asList( colors );
      vector.add( "black" );
      vector.add( "red" );
      vector.add( "green" );

      System.out.println( "Before addAll, vector contains:" );

      // display elements in vector
      for ( String s : vector )
         System.out.printf( "%s ", s );

      // add elements in colors to list
      Collections.addAll( vector, colors );

      System.out.println( "\n\nAfter addAll, vector contains: " );

      // display elements in vector
      for ( String s : vector )
         System.out.printf( "%s ", s );

      // get frequency of "red"
      int frequency = Collections.frequency( vector, "red" );
      System.out.printf( 
         "\n\nFrequency of red in vector: %d\n", frequency );

      // check whether list and vector have elements in common
      boolean disjoint = Collections.disjoint( list, vector );

      System.out.printf( "\nlist and vector %s elements in common\n", 
         ( disjoint ? "do not have" : "have"  ) );
   } // end Algorithms2 constructor

   public static void main( String args[] ) 
   {
      new Algorithms2();
   } // end main
} // end class Algorithms2

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
