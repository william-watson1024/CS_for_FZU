// Fig. 18.25: BackgroundCalculator.java
// SwingWorker subclass for calculating Fibonacci numbers
// in a background thread.
import javax.swing.SwingWorker;
import javax.swing.JLabel;
import java.util.concurrent.ExecutionException;

public class BackgroundCalculator extends SwingWorker< String, Object >
{
   private final int n; // Fibonacci number to calculate
   private final JLabel resultJLabel; // JLabel to display the result

   // constructor
   public BackgroundCalculator( int number, JLabel label )
   {
      n = number;
      resultJLabel = label;
   } // end BackgroundCalculator constructor

   // long-running code to be run in a worker thread
   public String doInBackground()
   {
      long nthFib = fibonacci( n );
      return String.valueOf( nthFib );
   } // end method doInBackground

   // code to run on the event dispatch thread when doInBackground returns
   protected void done()
   {
      try
      {
         // get the result of doInBackground and display it
         resultJLabel.setText( get() );
      } // end try
      catch ( InterruptedException ex ) 
      {
         resultJLabel.setText( "Interrupted while waiting for results." );
      } // end catch
      catch ( ExecutionException ex ) 
      {
         resultJLabel.setText( 
            "Error encountered while performing calculation." );
      } // end catch
   } // end method done

   // recursive method fibonacci; calculates nth Fibonacci number
   public long fibonacci( long number )
   {
      if ( number == 0 || number == 1 )
         return number;
      else 
         return fibonacci( number - 1 ) + fibonacci( number - 2 );
   } // end method fibonacci
} // end class BackgroundCalculator

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