// Fig. 20.28: DisplayQueryResults.java
// Display the contents of the Authors table in the books database.
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;
import java.util.regex.PatternSyntaxException;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.ScrollPaneConstants;
import javax.swing.JTable;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import javax.swing.Box;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.RowFilter;
import javax.swing.table.TableRowSorter;
import javax.swing.table.TableModel;

public class DisplayQueryResults extends JFrame 
{
   // database URL, username and password

   static final String DATABASE_URL = "jdbc:mysql://localhost/books?useUnicode = true & characterEncoding = utf-8 & useSSL = false & &serverTimezone = GMT";
   static final String USERNAME = "root";
   static final String PASSWORD = "123456";
   
   // default query retrieves all data from authors table
   static final String DEFAULT_QUERY = "SELECT * FROM authors";
   
   private ResultSetTableModel tableModel;
   private JTextArea queryArea;
   
   // create ResultSetTableModel and GUI
   public DisplayQueryResults() 
   {   
      super( "Displaying Query Results" );
        
      // create ResultSetTableModel and display database table
      try 
      {
         // create TableModel for results of query SELECT * FROM authors
         tableModel = new ResultSetTableModel( DATABASE_URL,
            USERNAME, PASSWORD, DEFAULT_QUERY );

         // set up JTextArea in which user types queries
         queryArea = new JTextArea( DEFAULT_QUERY, 3, 100 );
         queryArea.setWrapStyleWord( true );
         queryArea.setLineWrap( true );
         
         JScrollPane scrollPane = new JScrollPane( queryArea,
            ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED, 
            ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER );
         
         // set up JButton for submitting queries
         JButton submitButton = new JButton( "Submit Query" );

         // create Box to manage placement of queryArea and 
         // submitButton in GUI
         Box boxNorth = Box.createHorizontalBox();
         boxNorth.add( scrollPane );
         boxNorth.add( submitButton );

         // create JTable delegate for tableModel 
         JTable resultTable = new JTable( tableModel );
         
         JLabel filterLabel = new JLabel( "Filter:" );
         final JTextField filterText = new JTextField();
         JButton filterButton = new JButton( "Apply Filter" );
         Box boxSouth = boxNorth.createHorizontalBox();
         
         boxSouth.add( filterLabel );
         boxSouth.add( filterText );
         boxSouth.add( filterButton );
         
         // place GUI components on content pane
         add( boxNorth, BorderLayout.NORTH );
         add( new JScrollPane( resultTable ), BorderLayout.CENTER );
         add( boxSouth, BorderLayout.SOUTH );

         // create event listener for submitButton
         submitButton.addActionListener( 
         
            new ActionListener() 
            {
               // pass query to table model
               public void actionPerformed( ActionEvent event )
               {
                  // perform a new query
                  try 
                  {
                     tableModel.setQuery( queryArea.getText() );
                  } // end try
                  catch ( SQLException sqlException ) 
                  {
                     JOptionPane.showMessageDialog( null, 
                        sqlException.getMessage(), "Database error", 
                        JOptionPane.ERROR_MESSAGE );
                     
                     // try to recover from invalid user query 
                     // by executing default query
                     try 
                     {
                        tableModel.setQuery( DEFAULT_QUERY );
                        queryArea.setText( DEFAULT_QUERY );
                     } // end try
                     catch ( SQLException sqlException2 ) 
                     {
                        JOptionPane.showMessageDialog( null, 
                           sqlException2.getMessage(), "Database error", 
                           JOptionPane.ERROR_MESSAGE );
         
                        // ensure database connection is closed
                        tableModel.disconnectFromDatabase();
         
                        System.exit( 1 ); // terminate application
                     } // end inner catch                   
                  } // end outer catch
               } // end actionPerformed
            }  // end ActionListener inner class          
         ); // end call to addActionListener
         
         final TableRowSorter< TableModel > sorter = 
            new TableRowSorter< TableModel >( tableModel );
         resultTable.setRowSorter( sorter );
         setSize( 500, 250 ); // set window size
         setVisible( true ); // display window  
         
         // create listener for filterButton
         filterButton.addActionListener(            
            new ActionListener() 
            {
               // pass filter text to listener
               public void actionPerformed( ActionEvent e ) 
               {
                  String text = filterText.getText();

                  if ( text.length() == 0 )
                     sorter.setRowFilter( null );
                  else
                  {
                     try
                     {
                        sorter.setRowFilter( 
                           RowFilter.regexFilter( text ) );
                     } // end try
                     catch ( PatternSyntaxException pse ) 
                     {
                        JOptionPane.showMessageDialog( null,
                           "Bad regex pattern", "Bad regex pattern",
                           JOptionPane.ERROR_MESSAGE );
                     } // end catch
                  } // end else
               } // end method actionPerfomed
            } // end annonymous inner class
         ); // end call to addActionLister
      } // end try
      catch ( SQLException sqlException ) 
      {
         JOptionPane.showMessageDialog( null, sqlException.getMessage(), 
            "Database error", JOptionPane.ERROR_MESSAGE );
               
         // ensure database connection is closed
         tableModel.disconnectFromDatabase();
         
         System.exit( 1 ); // terminate application
      } // end catch
      
      // dispose of window when user quits application (this overrides
      // the default of HIDE_ON_CLOSE)
      setDefaultCloseOperation( DISPOSE_ON_CLOSE );
      
      // ensure database connection is closed when user quits application
      addWindowListener(
      
         new WindowAdapter() 
         {
            // disconnect from database and exit when window has closed
            public void windowClosed( WindowEvent event )
            {
               tableModel.disconnectFromDatabase();
               System.exit( 0 );
            } // end method windowClosed
         } // end WindowAdapter inner class
      ); // end call to addWindowListener
   } // end DisplayQueryResults constructor
   
   // execute application
   public static void main( String args[] ) 
   {
      new DisplayQueryResults();     
   } // end main
} // end class DisplayQueryResults



/**************************************************************************
 * (C) Copyright 1992-2009  by Deitel & Associates, Inc. and               *
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
