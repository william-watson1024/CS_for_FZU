//没什么参考价值，主要是为了引出多态而已
public class OverloadedMethods
{
   // method printArray to print Integer array
   public static void printArray( Integer[] inputArray )
   {
      // display array elements
      for ( Integer element : inputArray )
         System.out.printf( "%s ", element );

      System.out.println();
   } // end method printArray

   // method printArray to print Double array
   public static void printArray( Double[] inputArray )
   {
      // display array elements
      for ( Double element : inputArray )
         System.out.printf( "%s ", element );

      System.out.println();
   } // end method printArray

   // method printArray to print Character array
   public static void printArray( Character[] inputArray )
   {
      // display array elements
      for ( Character element : inputArray )
         System.out.printf( "%s ", element );

      System.out.println();
   } // end method printArray

   public static void main( String args[] ) 
   {
      // create arrays of Integer, Double and Character
      Integer[] integerArray = { 1, 2, 3, 4, 5, 6 };
      Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
      Character[] characterArray = { 'H', 'E', 'L', 'L', 'O' };

      System.out.println( "Array integerArray contains:" );
      printArray( integerArray ); // pass an Integer array
      System.out.println( "\nArray doubleArray contains:" );
      printArray( doubleArray ); // pass a Double array
      System.out.println( "\nArray characterArray contains:" );
      printArray( characterArray ); // pass a Character array
   } // end main
} // end class OverloadedMethods
