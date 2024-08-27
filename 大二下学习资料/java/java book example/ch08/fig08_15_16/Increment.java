// Fig. 8.15: Increment.java
// final instance variable in a class.

public class Increment 
{
   private int total = 0; // total of all increments
   private final int INCREMENT; // constant variable (uninitialized)

   // constructor initializes final instance variable INCREMENT
   public Increment( int incrementValue )
   {
      INCREMENT = incrementValue; // initialize constant variable (once)
   } // end Increment constructor

   // add INCREMENT to total
   public void addIncrementToTotal()
   {
      total += INCREMENT;
   } // end method addIncrementToTotal 

   // return String representation of an Increment object's data
   public String toString()
   {
      return String.format( "total = %d", total );
   } // end method toIncrementString
} // end class Increment


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
