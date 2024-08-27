// Fig. 11.25: MultipleSelectionFrame.java
// Copying items from one List to another.
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;

public class MultipleSelectionFrame extends JFrame 
{
   private JList colorJList; // list to hold color names
   private JList copyJList; // list to copy color names into
   private JButton copyJButton; // button to copy selected names
   private final String colorNames[] = { "Black", "Blue", "Cyan", 
      "Dark Gray", "Gray", "Green", "Light Gray", "Magenta", "Orange", 
      "Pink", "Red", "White", "Yellow" };

   // MultipleSelectionFrame constructor
   public MultipleSelectionFrame()
   {
      super( "Multiple Selection Lists" );
      setLayout( new FlowLayout() ); // set frame layout

      colorJList = new JList( colorNames ); // holds names of all colors
      colorJList.setVisibleRowCount( 5 ); // show five rows
      colorJList.setSelectionMode( 
         ListSelectionModel.MULTIPLE_INTERVAL_SELECTION );
      add( new JScrollPane( colorJList ) ); // add list with scrollpane

      copyJButton = new JButton( "Copy >>>" ); // create copy button
      copyJButton.addActionListener(

         new ActionListener() // anonymous inner class 
         {  
            // handle button event
            public void actionPerformed( ActionEvent event )
            {
               // place selected values in copyJList
               copyJList.setListData( colorJList.getSelectedValues() );
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener

      add( copyJButton ); // add copy button to JFrame

      copyJList = new JList(); // create list to hold copied color names
      copyJList.setVisibleRowCount( 5 ); // show 5 rows
      copyJList.setFixedCellWidth( 100 ); // set width
      copyJList.setFixedCellHeight( 15 ); // set height
      copyJList.setSelectionMode( 
         ListSelectionModel.SINGLE_INTERVAL_SELECTION );
      add( new JScrollPane( copyJList ) ); // add list with scrollpane
   } // end MultipleSelectionFrame constructor
} // end class MultipleSelectionFrame


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
