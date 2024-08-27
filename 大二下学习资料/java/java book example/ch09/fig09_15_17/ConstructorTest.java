// Fig. 9.17: ConstructorTest.java
// Display order in which superclass and subclass constructors are called.

public class ConstructorTest 
{
   public static void main( String args[] )
   {
      CommissionEmployee4 employee1 = new CommissionEmployee4( 
         "Bob", "Lewis", "333-33-3333", 5000, .04 );
      
      System.out.println();
      BasePlusCommissionEmployee5 employee2 = 
         new BasePlusCommissionEmployee5( 
         "Lisa", "Jones", "555-55-5555", 2000, .06, 800 );
      
      System.out.println();
      BasePlusCommissionEmployee5 employee3 = 
         new BasePlusCommissionEmployee5( 
         "Mark", "Sands", "888-88-8888", 8000, .15, 2000 );
   } // end main
} // end class ConstructorTest


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
