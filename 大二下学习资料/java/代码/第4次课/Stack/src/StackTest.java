// Fig. 15.10: StackTest.java
// Stack generic class test program.

public class StackTest 
{
   private double[] doubleElements = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
   private int[] integerElements = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

   private Stack< Double > doubleStack; // stack stores Double objects
   private Stack< Integer > integerStack; // stack stores Integer objects

   // test Stack objects
   public void testStacks()
   {
      doubleStack = new Stack< Double >( 5 ); // Stack of Doubles
      integerStack = new Stack< Integer >( 10 ); // Stack of Integers

      testPushDouble(); // push double onto doubleStack
      testPopDouble(); // pop from doubleStack
      testPushInteger(); // push int onto intStack
      testPopInteger(); // pop from intStack
   } // end method testStacks

   // test push method with double stack
   public void testPushDouble()
   {
      // push elements onto stack 
      try
      {
         System.out.println( "\nPushing elements onto doubleStack" );

         // push elements to Stack
         for ( double element : doubleElements )
         {
            System.out.printf( "%.1f ", element );
            doubleStack.push( element ); // push onto doubleStack
         } // end for
      } // end try
      catch ( FullStackException fullStackException )
      {
         System.err.println();
         fullStackException.printStackTrace();
      } // end catch FullStackException
   } // end method testPushDouble

   // test pop method with double stack
   public void testPopDouble()
   {
      // pop elements from stack
      try
      {
         System.out.println( "\nPopping elements from doubleStack" );
         double popValue; // store element removed from stack

         // remove all elements from Stack
         while ( true )
         {
            popValue = doubleStack.pop(); // pop from doubleStack
            System.out.printf( "%.1f ", popValue ); 
         } // end while
      } // end try
      catch( EmptyStackException emptyStackException )
      {
         System.err.println();
         emptyStackException.printStackTrace();
      } // end catch EmptyStackException
   } // end method testPopDouble

   // test push method with integer stack
   public void testPushInteger()
   {
      // push elements to stack 
      try
      {
         System.out.println( "\nPushing elements onto integerStack" );

         // push elements to Stack
         for ( int element : integerElements )
         {
            System.out.printf( "%d ", element );
            integerStack.push( element ); // push onto integerStack
         } // end for
      } // end try
      catch ( FullStackException fullStackException )
      {
         System.err.println();
         fullStackException.printStackTrace();
      } // end catch FullStackException
   } // end method testPushInteger

   // test pop method with integer stack
   public void testPopInteger()
   {
      // pop elements from stack
      try
      {
         System.out.println( "\nPopping elements from integerStack" );
         int popValue; // store element removed from stack

         // remove all elements from Stack
         while ( true )
         {
            popValue = integerStack.pop(); // pop from intStack
            System.out.printf( "%d ", popValue );
         } // end while
      } // end try
      catch( EmptyStackException emptyStackException )
      {
         System.err.println();
         emptyStackException.printStackTrace();
      } // end catch EmptyStackException
   } // end method testPopInteger

   public static void main( String args[] ) 
   {
      StackTest application = new StackTest();
      application.testStacks();
   } // end main
} // end class StackTest

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