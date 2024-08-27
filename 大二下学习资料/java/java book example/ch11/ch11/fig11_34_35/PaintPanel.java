// Fig. 11.32: PaintPanel.java
// Using class MouseMotionAdapter.
import java.awt.Point;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import javax.swing.JPanel;

public class PaintPanel extends JPanel 
{
   private int pointCount = 0; // count number of points

   // array of 10000 java.awt.Point references
   private Point points[] = new Point[ 10000 ];  

   // set up GUI and register mouse event handler
   public PaintPanel()
   {
      // handle frame mouse motion event
      addMouseMotionListener(

         new MouseMotionAdapter() // anonymous inner class
         {  
            // store drag coordinates and repaint
            public void mouseDragged( MouseEvent event )
            {
               if ( pointCount < points.length ) 
               {
                  points[ pointCount ] = event.getPoint(); // find point
                  pointCount++; // increment number of points in array
                  repaint(); // repaint JFrame
               } // end if
            } // end method mouseDragged
         } // end anonymous inner class
      ); // end call to addMouseMotionListener
   } // end PaintPanel constructor

   // draw oval in a 4-by-4 bounding box at specified location on window
   public void paintComponent( Graphics g )
   {
      super.paintComponent( g ); // clears drawing area

      // draw all points in array
      for ( int i = 0; i < pointCount; i++ )
         g.fillOval( points[ i ].x, points[ i ].y, 4, 4 );
   } // end method paint
} // end class PaintPanel


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