// Fig. 15.9: EmptyStackException.java
// Indicates a stack is full.
public class EmptyStackException extends RuntimeException
{
   // no-argument constructor
   public EmptyStackException()
   {
      this( "Stack is empty" );
   } // end no-argument EmptyStackException constructor 

   // one-argument constructor
   public EmptyStackException( String exception )
   {
      super( exception );
   } // end one-argument EmptyStackException constructor
} // end class EmptyStackException


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