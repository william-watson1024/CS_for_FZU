// Fig. 11.36: KeyDemoFrame.java
// Demonstrating keystroke events.
import java.awt.Color;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class KeyDemoFrame extends JFrame implements KeyListener 
{
   private String line1 = ""; // first line of textarea
   private String line2 = ""; // second line of textarea
   private String line3 = ""; // third line of textarea
   private JTextArea textArea; // textarea to display output

   // KeyDemoFrame constructor
   public KeyDemoFrame()
   {
      super( "Demonstrating Keystroke Events" );

      textArea = new JTextArea( 10, 15 ); // set up JTextArea
      textArea.setText( "Press any key on the keyboard..." );
      textArea.setEnabled( false ); // disable textarea
      textArea.setDisabledTextColor( Color.BLACK ); // set text color
      add( textArea ); // add textarea to JFrame

      addKeyListener( this ); // allow frame to process key events
   } // end KeyDemoFrame constructor

   // handle press of any key
   public void keyPressed( KeyEvent event )
   {
      line1 = String.format( "Key pressed: %s", 
         event.getKeyText( event.getKeyCode() ) ); // output pressed key
      setLines2and3( event ); // set output lines two and three
   } // end method keyPressed

   // handle release of any key
   public void keyReleased( KeyEvent event )
   {
      line1 = String.format( "Key released: %s",
         event.getKeyText( event.getKeyCode() ) ); // output released key
      setLines2and3( event ); // set output lines two and three
   } // end method keyReleased

   // handle press of an action key
   public void keyTyped( KeyEvent event )
   {
      line1 = String.format( "Key typed: %s", event.getKeyChar() );
      setLines2and3( event ); // set output lines two and three
   } // end method keyTyped

   // set second and third lines of output
   private void setLines2and3( KeyEvent event )
   {
      line2 = String.format( "This key is %san action key", 
         ( event.isActionKey() ? "" : "not " ) );

      String temp = event.getKeyModifiersText( event.getModifiers() );

      line3 = String.format( "Modifier keys pressed: %s", 
         ( temp.equals( "" ) ? "none" : temp ) ); // output modifiers

      textArea.setText( String.format( "%s\n%s\n%s\n", 
         line1, line2, line3 ) ); // output three lines of text
   } // end method setLines2and3
} // end class KeyDemoFrame


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
