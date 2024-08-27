// Fig. 14.17: AccountRecordSerializable.java
// A class that represents one record of information.
package com.deitel.jhtp7.ch14; // packaged for reuse

import java.io.Serializable;

public class AccountRecordSerializable implements Serializable
{
   private int account;
   private String firstName;
   private String lastName;
   private double balance;
   
   // no-argument constructor calls other constructor with default values
   public AccountRecordSerializable() 
   {
      this( 0, "", "", 0.0 );
   } // end no-argument AccountRecordSerializable constructor
  
   // four-argument constructor initializes a record
   public AccountRecordSerializable(
      int acct, String first, String last, double bal )
   {
      setAccount( acct );
      setFirstName( first );
      setLastName( last );
      setBalance( bal );
   } // end four-argument AccountRecordSerializable constructor

   // set account number   
   public void setAccount( int acct )
   {
      account = acct;
   } // end method setAccount

   // get account number   
   public int getAccount() 
   { 
      return account; 
   } // end method getAccount
   
   // set first name   
   public void setFirstName( String first )
   {
      firstName = first;
   } // end method setFirstName

   // get first name   
   public String getFirstName() 
   { 
      return firstName; 
   } // end method getFirstName
   
   // set last name   
   public void setLastName( String last )
   {
      lastName = last;
   } // end method setLastName

   // get last name   
   public String getLastName() 
   {
      return lastName; 
   } // end method getLastName
   
   // set balance  
   public void setBalance( double bal )
   {
      balance = bal;
   } // end method setBalance

   // get balance   
   public double getBalance() 
   { 
      return balance; 
   } // end method getBalance
} // end class AccountRecordSerializable

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