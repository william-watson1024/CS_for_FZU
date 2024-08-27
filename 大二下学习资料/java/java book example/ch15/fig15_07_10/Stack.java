// Fig. 15.7: Stack.java
// Generic class Stack.

public class Stack< E >  
{
   private final int size; // number of elements in the stack
   private int top; // location of the top element
   private E[] elements; // array that stores stack elements

   // no-argument constructor creates a stack of the default size
   public Stack()
   {
      this( 10 ); // default stack size
   } // end no-argument Stack constructor
   
   // constructor creates a stack of the specified number of elements
   public Stack( int s )
   {
      size = s > 0 ? s : 10; // set size of Stack
      top = -1; // Stack initially empty

      elements = ( E[] ) new Object[ size ]; // create array 
   } // end one-argument Stack constructor

   // push element onto stack; if successful, return true; 
   // otherwise, throw FullStackException
   public void push( E pushValue )
   {
      if ( top == size - 1 ) // if stack is full
         throw new FullStackException( String.format( 
            "Stack is full, cannot push %s", pushValue ) );

      elements[ ++top ] = pushValue; // place pushValue on Stack
   } // end method push

   // return the top element if not empty; else throw EmptyStackException
   public E pop()
   {
      if ( top == -1 ) // if stack is empty
         throw new EmptyStackException( "Stack is empty, cannot pop" );

      return elements[ top-- ]; // remove and return top element of Stack
   } // end method pop
} // end class Stack< E >

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