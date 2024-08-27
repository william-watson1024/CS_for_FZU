// Fig. 13.5: UsingExceptions.java
// Demonstration of the try...catch...finally exception handling
// mechanism.

public class UsingExceptions 
{
   public static void main( String args[] )
   {
      try 
      { 
         throwException(); // call method throwException
      } // end try
      catch ( Exception exception ) // exception thrown by throwException
      {
         System.err.println( "Exception handled in main" );
      } // end catch

      doesNotThrowException();
   } // end main

   // demonstrate try...catch...finally
   public static void throwException() throws Exception
   {
      try // throw an exception and immediately catch it
      { 
         System.out.println( "Method throwException" );
         throw new Exception(); // generate exception
      } // end try
      catch ( Exception exception ) // catch exception thrown in try
      {
         System.err.println(
            "Exception handled in method throwException" );
         throw exception; // rethrow for further processing

         // any code here would not be reached, exception rethrown in catch

      } // end catch
      finally // executes regardless of what occurs in try...catch
      {
         System.err.println( "Finally executed in throwException" );
      } // end finally

      // any code here would not be reached

   } // end method throwException

   // demonstrate finally when no exception occurs
   public static void doesNotThrowException()
   {
      try // try block does not throw an exception
      { 
         System.out.println( "Method doesNotThrowException" );
      } // end try
      catch ( Exception exception ) // does not execute
      {
         System.err.println( exception );
      } // end catch
      finally // executes regardless of what occurs in try...catch
      {
         System.err.println( 
            "Finally executed in doesNotThrowException" );
      } // end finally

      System.out.println( "End of method doesNotThrowException" );
   } // end method doesNotThrowException
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
