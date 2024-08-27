// Fig. 21.6: Time.java
// Page bean file that sets clockText to the time on the web server
package webtime;

import com.sun.rave.web.ui.appbase.AbstractPageBean;
import com.sun.webui.jsf.component.StaticText;
import javax.faces.FacesException;
import java.text.DateFormat;
import java.util.Date;

public class Time extends AbstractPageBean
{
   private void _init() throws Exception
   {
   } // end method _init

   private StaticText clockText = new StaticText();

   public StaticText getClockText()
   {
      return clockText;
   } // end method getClockText

   public void setClockText( StaticText st )
   {
      this.clockText = st;
   } // end method setClockText

   public Time()
   {
   } // end constructor 

   @Override
   public void init()
   {
      super.init();

      try 
      {
         _init();
      } // end try
      catch ( Exception e ) 
      {
         log( "Page1 Initialization Failure" , e );
         throw e instanceof FacesException ? ( FacesException ) e : 
            new FacesException( e );
      } // end catch
   } // end method init

   // method called when a postback occurs
   @Override
   public void preprocess()
   {
   } // end method preprocess

   // method called before the page is rendered
   @Override
   public void prerender()
   {
      clockText.setValue( DateFormat.getTimeInstance(
         DateFormat.LONG ).format( new Date() ) );
   } // end method prerender

   // method called after rendering completes, if init was called
   @Override
   public void destroy()
   {
   } // end method 

   // returns a reference to the session bean
   protected SessionBean1 getSessionBean1()
   {
      return ( SessionBean1 ) getBean( "SessionBean1" );
   } // end method 

   // returns a reference to the request bean
   protected RequestBean1 getRequestBean1()
   {
      return ( RequestBean1 ) getBean( "RequestBean1" );
   } // end method 

   // returns a reference to the application bean
   protected ApplicationBean1 getApplicationBean1()
   {
      return ( ApplicationBean1 ) getBean( "ApplicationBean1" );
   } // end method 
} // end class Time

/*************************************************************************
 * (C) Copyright 1992-2009 by Deitel & Associates, Inc. and              *
 * Pearson Education, Inc. All Rights Reserved.                          *
 *                                                                       *
 * DISCLAIMER: The authors and publisher of this book have used their    *
 * best efforts in preparing the book. These efforts include the         *
 * development, research, and testing of the theories and programs       *
 * to determine their effectiveness. The authors and publisher make      *
 * no warranty of any kind, expressed or implied, with regard to these   *
 * programs or to the documentation contained in these books. The authors*
 * and publisher shall not be liable in any event for incidental or      *
 * consequential damages in connection with, or arising out of, the      *
 * furnishing, performance, or use of these programs.                    *
 ************************************************************************/
