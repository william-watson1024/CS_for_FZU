// Fig. 14.5: FileDemonstrationTest.java
// Testing the FileDemonstration class.
import java.util.Scanner;
import java.io.File;
import java.net.URI;

public class Test
{
   public static void main( String args[] )
   {
      try
      {
         File testFile = new File( "C:\\books\\2004\\sjhtp7e\\frame\\jhtp7_14_Files.fm" );
         System.out.println( testFile.toURI().toString() );
      }
      catch ( Exception exception )
      {
         System.out.println( "exception" );
      }
   } // end main
} // end class Test

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