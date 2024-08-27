// Fig. 19.2: SiteSelector.java
// This program loads a document from a URL.
import java.net.MalformedURLException;
import java.net.URL;
import java.util.HashMap;
import java.util.ArrayList;
import java.awt.BorderLayout;
import java.applet.AppletContext;
import javax.swing.JApplet;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class SiteSelector extends JApplet 
{
   private HashMap< Object, URL > sites; // site names and URLs
   private ArrayList< String > siteNames; // site names
   private JList siteChooser; // list of sites to choose from

   // read HTML parameters and set up GUI
   public void init()
   {
      sites = new HashMap< Object, URL >(); // create HashMap
      siteNames = new ArrayList< String >(); // create ArrayList

      // obtain parameters from HTML document
      getSitesFromHTMLParameters(); 

      // create GUI components and layout interface
      add( new JLabel( "Choose a site to browse" ), BorderLayout.NORTH );

      siteChooser = new JList( siteNames.toArray() ); // populate JList
      siteChooser.addListSelectionListener(
         new ListSelectionListener() // anonymous inner class
         {
            // go to site user selected
            public void valueChanged( ListSelectionEvent event )
            {
               // get selected site name
               Object object = siteChooser.getSelectedValue();

               // use site name to locate corresponding URL
               URL newDocument = sites.get( object );

               // get applet container
               AppletContext browser = getAppletContext();

               // tell applet container to change pages
               browser.showDocument( newDocument );
            } // end method valueChanged
         } // end anonymous inner class
      ); // end call to addListSelectionListener

      add( new JScrollPane( siteChooser ), BorderLayout.CENTER );
   } // end method init

   // obtain parameters from HTML document
   private void getSitesFromHTMLParameters()
   {
      String title; // site title
      String location; // location of site
      URL url; // URL of location
      int counter = 0; // count number of sites

      title = getParameter( "title" + counter ); // get first site title

      // loop until no more parameters in HTML document
      while ( title != null ) 
      {
         // obtain site location
         location = getParameter( "location" + counter );
            
         try // place title/URL in HashMap and title in ArrayList
         {
            url = new URL( location ); // convert location to URL
            sites.put( title, url ); // put title/URL in HashMap
            siteNames.add( title ); // put title in ArrayList
         } // end try
         catch ( MalformedURLException urlException ) 
         {
            urlException.printStackTrace();
         } // end catch

         counter++;
         title = getParameter( "title" + counter ); // get next site title
      } // end while
   } // end method getSitesFromHTMLParameters
} // end class SiteSelector

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
