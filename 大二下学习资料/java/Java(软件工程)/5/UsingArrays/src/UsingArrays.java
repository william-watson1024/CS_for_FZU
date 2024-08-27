// Fig. 19.2: UsingArrays.java
// Using Java arrays.
import java.util.Arrays;

public class UsingArrays 
{
   private int intArray[] = { 1, 2, 3, 4, 5, 6 };
   private double doubleArray[] = { 8.4, 9.3, 0.2, 7.9, 3.4 };
   private int filledIntArray[], intArrayCopy[];

   // constructor initializes arrays
   public UsingArrays()
   {
      filledIntArray = new int[ 10 ]; // create int array with 10 elements
      intArrayCopy = new int[ intArray.length ];

      Arrays.fill( filledIntArray, 7 ); // fill with 7s
      Arrays.sort( doubleArray ); // sort doubleArray ascending

      // copy array intArray into array intArrayCopy
      System.arraycopy( intArray, 0, intArrayCopy,
         0, intArray.length );
   } // end UsingArrays constructor

   // output values in each array
   public void printArrays()
   {     
      System.out.print( "doubleArray: " );
      for ( double doubleValue : doubleArray )
         System.out.printf( "%.1f ", doubleValue );

      System.out.print( "\nintArray: " );
      for ( int intValue : intArray )
         System.out.printf( "%d ", intValue );

      System.out.print( "\nfilledIntArray: " );
      for ( int intValue : filledIntArray )
         System.out.printf( "%d ", intValue );

      System.out.print( "\nintArrayCopy: " );
      for ( int intValue : intArrayCopy )
         System.out.printf( "%d ", intValue );

      System.out.println( "\n" );
   } // end method printArrays

   // find value in array intArray
   public int searchForInt( int value )
   {  
      return Arrays.binarySearch( intArray, value );
   } // end method searchForInt

   // compare array contents
   public void printEquality()
   {
      boolean b = Arrays.equals( intArray, intArrayCopy );
      System.out.printf( "intArray %s intArrayCopy\n",
         ( b ? "==" : "!=" ) );

      b = Arrays.equals( intArray, filledIntArray );
      System.out.printf( "intArray %s filledIntArray\n", 
         ( b ? "==" : "!=" ) );
   } // end method printEquality

   public static void main( String args[] )
   {
      UsingArrays usingArrays = new UsingArrays();

      usingArrays.printArrays();
      usingArrays.printEquality();

      int location = usingArrays.searchForInt( 5 );
      if ( location >= 0 )
         System.out.printf( 
            "Found 5 at element %d in intArray\n", location ); 
      else
         System.out.println( "5 not found in intArray" ); 

      location = usingArrays.searchForInt( 8763 );
      if ( location >= 0 )
         System.out.printf( 
            "Found 8763 at element %d in intArray\n", location ); 
      else
         System.out.println( "8763 not found in intArray" ); 
   } // end main
} // end class UsingArrays

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
