// Fig. 18.12: Producer.java
// Producer with a run method that inserts the values 1 to 10 in buffer.
import java.util.Random;

public class Producer implements Runnable
{
   private final static Random generator = new Random();
   private final Buffer sharedLocation; // reference to shared object

   // constructor
   public Producer( Buffer shared )
   {
       sharedLocation = shared;
   } // end Producer constructor

   // store values from 1 to 10 in sharedLocation
   public void run()                             
   {
      int sum = 0;

      for ( int count = 1; count <= 10; count++ )
      {
         try // sleep 0 to 3 seconds, then place value in Buffer
         {
            Thread.sleep( generator.nextInt( 3000 ) ); // random sleep
            sharedLocation.set( count ); // set value in buffer
            sum += count; // increment sum of values
            System.out.printf( "\t%2d\n", sum );
         } // end try
         // if lines 25 or 26 get interrupted, print stack trace
         catch ( InterruptedException exception ) 
         {
            exception.printStackTrace();
         } // end catch
      } // end for

      System.out.println( 
         "Producer done producing\nTerminating Producer" );
   } // end method run
} // end class Producer



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