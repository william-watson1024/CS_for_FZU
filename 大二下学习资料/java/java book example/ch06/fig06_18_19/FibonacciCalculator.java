// Fig. 6.18: FibonacciCalculator.java
// Recursive fibonacci method.

public class FibonacciCalculator
{
   // recursive declaration of method fibonacci
   public long fibonacci( long number )
   {
      if ( ( number == 0 ) || ( number == 1 ) ) // base cases
         return number;
      else // recursion step
         return fibonacci( number - 1 ) + fibonacci( number - 2 );
   } // end method fibonacci

   public void displayFibonacci()
   {
      for ( int counter = 0; counter <= 10; counter++ )
         System.out.printf( "Fibonacci of %d is: %d\n", counter,
            fibonacci( counter ) );
   } // end method displayFibonacci
} // end class FibonacciCalculator

/*************************************************************************
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