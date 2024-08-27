// Fig. 18.5: ThreadCreator.java
// Creating and starting three threads to execute Runnables.
import java.lang.Thread;

public class ThreadCreator
{
   public static void main( String[] args )
   {
      System.out.println( "Creating threads" );

      // create each thread with a new targeted runnable
      Thread thread1 = new Thread( new PrintTask( "task1" ) );
      Thread thread2 = new Thread( new PrintTask( "task2" ) );
      Thread thread3 = new Thread( new PrintTask( "task3" ) );

      System.out.println( "Threads created, starting tasks." );

      // start threads and place in runnable state
      thread1.start(); // invokes task1’s run method
      thread2.start(); // invokes task2’s run method
      thread3.start(); // invokes task3’s run method

      System.out.println( "Tasks started, main ends.\n" );
   } // end main
} // end class RunnableTester   
     


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