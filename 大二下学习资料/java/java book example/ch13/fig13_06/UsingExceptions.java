// Fig. 13.6: UsingExceptions.java
// Demonstration of stack unwinding.

public class UsingExceptions 
{
   public static void main( String args[] )
   {
      try // call throwException to demonstrate stack unwinding
      { 
         throwException();
      } // end try
      catch ( Exception exception ) // exception thrown in throwException
      {
         System.err.println( "Exception handled in main" );
      } // end catch
   } // end main

   // throwException throws exception that is not caught in this method
   public static void throwException() throws Exception
   {
      try // throw an exception and catch it in main
      { 
         System.out.println( "Method throwException" );
         throw new Exception(); // generate exception
      } // end try
      catch ( RuntimeException runtimeException ) // catch incorrect type
      {
         System.err.println( 
            "Exception handled in method throwException" );
      } // end catch
      finally // finally block always executes
      { 
         System.err.println( "Finally is always executed" );
      } // end finally
   } // end method throwException
} // end class UsingExceptions

/**************************************************************************
 * (C) Copyright 1992-2005 by Deitel & Associates, Inc. and               *
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
