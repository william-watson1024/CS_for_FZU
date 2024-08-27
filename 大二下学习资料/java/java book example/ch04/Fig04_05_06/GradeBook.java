// Fig. 4.5: GradeBook.java
// GradeBook class that solves class-average problem using 
// counter-controlled repetition.
import java.util.Scanner; // program uses class Scanner

public class GradeBook 
{
   private String courseName; // name of course this GradeBook represents

   // constructor initializes courseName
   public GradeBook( String name )
   {
      courseName = name; // initializes courseName
   } // end constructor

   // method to set the course name
   public void setCourseName( String name )
   {
      courseName = name; // store the course name
   } // end method setCourseName

   // method to retrieve the course name
   public String getCourseName()
   {
      return courseName;
   } // end method getCourseName

   // display a welcome message to the GradeBook user
   public void displayMessage()
   {
      // getCourseName gets the name of the course
      System.out.printf( "Welcome to the grade book for\n%s!\n\n", 
         getCourseName() );
   } // end method displayMessage

   // determine class average based on 10 grades entered by user
   public void determineClassAverage() 
   {
      // create Scanner to obtain input from command window
      Scanner input = new Scanner( System.in );

      int total; // sum of grades entered by user
      int gradeCounter; // number of the grade to be entered next
      int grade; // grade value entered by user
      int average; // average of grades

      // initialization phase
      total = 0; // initialize total
      gradeCounter = 1; // initialize loop counter
   
      // processing phase
      while ( gradeCounter <= 10 ) // loop 10 times
      {
         System.out.print( "Enter grade: " ); // prompt 
         grade = input.nextInt(); // read grade from user
         total = total + grade; // add grade to total
         gradeCounter = gradeCounter + 1; // increment counter by 1
      } // end while
   
      // termination phase
      average = total / 10; // integer division yields integer result

      // display total and average of grades
      System.out.printf( "\nTotal of all 10 grades is %d\n", total );
      System.out.printf( "Class average is %d\n", average );
   } // end method determineClassAverage

} // end class GradeBook

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
