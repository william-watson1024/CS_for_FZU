// Fig. 8.10: Book.java
// Declare an enum type with constructor and explicit instance fields 
// and accessors for these fields

public enum Book
{    
   // declare constants of enum type                                
   JHTP6( "Java How to Program 6e", "2005" ),                        
   CHTP4( "C How to Program 4e", "2004" ),                           
   IW3HTP3( "Internet & World Wide Web How to Program 3e", "2004" ),
   CPPHTP4( "C++ How to Program 4e", "2003" ),                       
   VBHTP2( "Visual Basic .NET How to Program 2e", "2002" ),
   CSHARPHTP( "C# How to Program", "2002" );

   // instance fields 
   private final String title; // book title
   private final String copyrightYear; // copyright year

   // enum constructor
   Book( String bookTitle, String year ) 
   { 
      title = bookTitle;
      copyrightYear = year;
   } // end enum Book constructor

   // accessor for field title
   public String getTitle()
   {
      return title;
   } // end method getTitle

   // accessor for field copyrightYear
   public String getCopyrightYear()
   {
      return copyrightYear;
   } // end method getCopyrightYear
} // end enum Book


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
