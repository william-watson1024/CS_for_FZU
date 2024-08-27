// Fig. 9.8: BasePlusCommissionEmployee2.java
// BasePlusCommissionEmployee2 inherits from class CommissionEmployee.

public class BasePlusCommissionEmployee2 extends CommissionEmployee
{
   private double baseSalary; // base salary per week

   // six-argument constructor
   public BasePlusCommissionEmployee2( String first, String last, 
      String ssn, double sales, double rate, double salary )
   {
      // explicit call to superclass CommissionEmployee constructor
      super( first, last, ssn, sales, rate );

      setBaseSalary( salary ); // validate and store base salary
   } // end six-argument BasePlusCommissionEmployee2 constructor
   
   // set base salary
   public void setBaseSalary( double salary )
   {
      baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
   } // end method setBaseSalary

   // return base salary
   public double getBaseSalary()
   {
      return baseSalary;
   } // end method getBaseSalary

   // calculate earnings
   public double earnings()
   {
      // not allowed: commissionRate and grossSales private in superclass
      return baseSalary + ( commissionRate * grossSales );
   } // end method earnings

   // return String representation of BasePlusCommissionEmployee2
   public String toString()
   {
      // not allowed: attempts to access private superclass members   
      return String.format( 
         "%s: %s %s\n%s: %s\n%s: %.2f\n%s: %.2f\n%s: %.2f", 
         "base-salaried commission employee", firstName, lastName, 
         "social security number", socialSecurityNumber, 
         "gross sales", grossSales, "commission rate", commissionRate, 
         "base salary", baseSalary );
   } // end method toString
} // end class BasePlusCommissionEmployee2


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
