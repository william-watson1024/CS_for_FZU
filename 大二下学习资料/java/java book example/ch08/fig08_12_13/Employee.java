// Fig. 8.12: Employee.java
// Static variable used to maintain a count of the number of 
// Employee objects in memory.

public class Employee 
{
   private String firstName;
   private String lastName;
   private static int count = 0; // number of objects in memory

   // initialize employee, add 1 to static count and 
   // output String indicating that constructor was called
   public Employee( String first, String last )
   {
      firstName = first;
      lastName = last;

      count++;  // increment static count of employees
      System.out.printf( "Employee constructor: %s %s; count = %d\n",
         firstName, lastName, count );
   } // end Employee constructor

   // subtract 1 from static count when garbage 
   // collector calls finalize to clean up object;
   // confirm that finalize was called
   protected void finalize()
   {
      count--; // decrement static count of employees
      System.out.printf( "Employee finalizer: %s %s; count = %d\n",
         firstName, lastName, count );
   } // end method finalize

   // get first name
   public String getFirstName() 
   { 
      return firstName; 
   } // end method getFirstName

   // get last name
   public String getLastName() 
   { 
      return lastName; 
   } // end method getLastName

   // static method to get static count value
   public static int getCount() 
   { 
      return count; 
   } // end method getCount
} // end class Employee



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
