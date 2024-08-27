// Fig. 11.17: CheckBoxFrame.java
// Creating JCheckBox buttons.
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JCheckBox;

public class CheckBoxFrame extends JFrame 
{
   private JTextField textField; // displays text in changing fonts
   private JCheckBox boldJCheckBox; // to select/deselect bold
   private JCheckBox italicJCheckBox; // to select/deselect italic

   // CheckBoxFrame constructor adds JCheckBoxes to JFrame
   public CheckBoxFrame()
   {
      super( "JCheckBox Test" );
      setLayout( new FlowLayout() ); // set frame layout

      // set up JTextField and set its font
      textField = new JTextField( "Watch the font style change", 20 );
      textField.setFont( new Font( "Serif", Font.PLAIN, 14 ) );
      add( textField ); // add textField to JFrame

      boldJCheckBox = new JCheckBox( "Bold" ); // create bold checkbox
      italicJCheckBox = new JCheckBox( "Italic" ); // create italic
      add( boldJCheckBox ); // add bold checkbox to JFrame
      add( italicJCheckBox ); // add italic checkbox to JFrame

      // register listeners for JCheckBoxes
      CheckBoxHandler handler = new CheckBoxHandler();
      boldJCheckBox.addItemListener( handler );
      italicJCheckBox.addItemListener( handler );
   } // end CheckBoxFrame constructor

   // private inner class for ItemListener event handling
   private class CheckBoxHandler implements ItemListener 
   {
      private int valBold = Font.PLAIN; // controls bold font style
      private int valItalic = Font.PLAIN; // controls italic font style

      // respond to checkbox events
      public void itemStateChanged( ItemEvent event )
      {
         // process bold checkbox events
         if ( event.getSource() == boldJCheckBox )
            valBold = 
               boldJCheckBox.isSelected() ? Font.BOLD : Font.PLAIN;
               
         // process italic checkbox events
         if ( event.getSource() == italicJCheckBox )
            valItalic = 
               italicJCheckBox.isSelected() ? Font.ITALIC : Font.PLAIN;

         // set text field font
         textField.setFont( 
            new Font( "Serif", valBold + valItalic, 14 ) );
      } // end method itemStateChanged
   } // end private inner class CheckBoxHandler
} // end class CheckBoxFrame

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
