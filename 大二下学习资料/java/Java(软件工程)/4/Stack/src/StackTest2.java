// Fig. 15.11: StackTest2.java
// Stack generic class test program.

public class StackTest2 
{
   private Double[] doubleElements = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
   private Integer[] integerElements = 
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

   private Stack< Double > doubleStack; // stack stores Double objects
   private Stack< Integer > integerStack; // stack stores Integer objects

   // test Stack objects
   public void testStacks()
   {
      doubleStack = new Stack< Double >( 5 ); // Stack of Doubles
      integerStack = new Stack< Integer >( 10 ); // Stack of Integers

      testPush( "doubleStack", doubleStack, doubleElements );
      testPop( "doubleStack", doubleStack );
      testPush( "integerStack", integerStack, integerElements );
      testPop( "integerStack", integerStack );
   } // end method testStacks

   // generic method testPush pushes elements onto a Stack
   public < T > void testPush( String name, Stack< T > stack, 
      T[] elements )
   {
      // push elements onto stack 
      try
      {
         System.out.printf( "\nPushing elements onto %s\n", name );

         // push elements onto Stack
         for ( T element : elements )
         {
            System.out.printf( "%s ", element );
            stack.push( element ); // push element onto stack
         }
      } // end try
      catch ( FullStackException fullStackException )
      {
         System.out.println();
         fullStackException.printStackTrace();
      } // end catch FullStackException
   } // end method testPush

   // generic method testPop pops elements from a Stack
   public < T > void testPop( String name, Stack< T > stack )
   {
      // pop elements from stack
      try
      {
         System.out.printf( "\nPopping elements from %s\n", name );
         T popValue; // store element removed from stack

         // remove all elements from Stack
         while ( true )
         {
            popValue = stack.pop(); // pop from stack
            System.out.printf( "%s ", popValue );
         } // end while
      } // end try
      catch( EmptyStackException emptyStackException )
      {
         System.out.println();
         emptyStackException.printStackTrace();
      } // end catch EmptyStackException
   } // end method testPop

   public static void main( String args[] ) 
   {
      StackTest2 application = new StackTest2();
      application.testStacks(); 
   } // end main
} // end class StackTest2

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