// Fig. 18.18: SynchronizedBuffer.java
// Synchronizing access to shared data using Object 
// methods wait and notify.
public class SynchronizedBuffer implements Buffer
{
   private int buffer = -1; // shared by producer and consumer threads
   private boolean occupied = false;// whether the buffer is occupied
   
   // place value into buffer
   public synchronized void set( int value ) throws InterruptedException
   {
      // while there are no empty locations, place thread in waiting state
      while ( occupied ) 
      {
         // output thread information and buffer information, then wait
         System.out.println( "Producer tries to write." );
         displayState( "Buffer full. Producer waits." );
         wait();
      } // end while
        
      buffer = value; // set new buffer value
        
      // indicate producer cannot store another value
      // until consumer retrieves current buffer value
      occupied = true;
        
      displayState( "Producer writes " + buffer );
      
      notifyAll(); // tell waiting thread(s) to enter runnable state
   } // end method set; releases lock on SynchronizedBuffer 
    
   // return value from buffer
   public synchronized int get() throws InterruptedException
   {
      // while no data to read, place thread in waiting state
      while ( !occupied )
      {
         // output thread information and buffer information, then wait
         System.out.println( "Consumer tries to read." );
         displayState( "Buffer empty. Consumer waits." );
         wait();
      } // end while

      // indicate that producer can store another value 
      // because consumer just retrieved buffer value
      occupied = false;

      displayState( "Consumer reads " + buffer );
      
      notifyAll(); // tell waiting thread(s) to enter runnable state

      return buffer;
   } // end method get; releases lock on SynchronizedBuffer 
    
   // display current operation and buffer state
   public void displayState( String operation )
   {
      System.out.printf( "%-40s%d\t\t%b\n\n", operation, buffer, 
         occupied );
   } // end method displayState
} // end class SynchronizedBuffer



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