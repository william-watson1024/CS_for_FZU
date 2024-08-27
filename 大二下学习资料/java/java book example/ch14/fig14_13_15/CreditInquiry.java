// Fig. 14.14: CreditInquiry.java
// This program reads a file sequentially and displays the
// contents based on the type of account the user requests 
// (credit balance, debit balance or zero balance).
import java.io.File;
import java.io.FileNotFoundException;
import java.lang.IllegalStateException;
import java.util.NoSuchElementException;
import java.util.Scanner;

import com.deitel.jhtp7.ch14.AccountRecord;

public class CreditInquiry
{
   private MenuOption accountType;
   private Scanner input;
   private MenuOption choices[] = { MenuOption.ZERO_BALANCE,
      MenuOption.CREDIT_BALANCE, MenuOption.DEBIT_BALANCE,
      MenuOption.END };

   // read records from file and display only records of appropriate type
   private void readRecords()
   {
      // object to be written to file
      AccountRecord record = new AccountRecord(); 

      try // read records
      {     
         // open file to read from beginning
         input = new Scanner( new File( "clients.txt" ) );

         while ( input.hasNext() ) // input the values from the file
         {
            record.setAccount( input.nextInt() ); // read account number
            record.setFirstName( input.next() ); // read first name
            record.setLastName( input.next() ); // read last name
            record.setBalance( input.nextDouble() ); // read balance

            // if proper acount type, display record
            if ( shouldDisplay( record.getBalance() ) )
               System.out.printf( "%-10d%-12s%-12s%10.2f\n",
                  record.getAccount(), record.getFirstName(),
                  record.getLastName(), record.getBalance() );
         } // end while
      } // end try
      catch ( NoSuchElementException elementException )
      {
         System.err.println( "File improperly formed." );
         input.close();
         System.exit( 1 );
      } // end catch
      catch ( IllegalStateException stateException )
      {
         System.err.println( "Error reading from file." );
         System.exit( 1 );
      } // end catch
      catch ( FileNotFoundException fileNotFoundException )
      {
         System.err.println( "File cannot be found." );
         System.exit( 1 );
      } // end catch
      finally
      {
         if ( input != null )
            input.close(); // close the Scanner and the file
      } // end finally
   } // end method readRecords

   // use record type to determine if record should be displayed
   private boolean shouldDisplay( double balance )
   {
      if ( ( accountType == MenuOption.CREDIT_BALANCE )
         && ( balance < 0 ) )
         return true;

      else if ( ( accountType == MenuOption.DEBIT_BALANCE )
         && ( balance > 0 ) )
         return true;

      else if ( ( accountType == MenuOption.ZERO_BALANCE )
         && ( balance == 0 ) )
         return true;

      return false;
   } // end method shouldDisplay

   // obtain request from user
   private MenuOption getRequest()
   {
      Scanner textIn = new Scanner( System.in );
      int request = 1;

      // display request options
      System.out.printf( "\n%s\n%s\n%s\n%s\n%s\n",
         "Enter request", " 1 - List accounts with zero balances",
         " 2 - List accounts with credit balances",
         " 3 - List accounts with debit balances", " 4 - End of run" );

      try // attempt to input menu choice
      {
         do // input user request
         {
            System.out.print( "\n? " );
            request = textIn.nextInt();
         } while ( ( request < 1 ) || ( request > 4 ) );
      } // end try
      catch ( NoSuchElementException elementException )
      {
         System.err.println( "Invalid input." );
         System.exit( 1 );
      } // end catch

      return choices[ request - 1 ]; // return enum value for option
   } // end method getRequest

   public void processRequests()
   {
      // get user's request (e.g., zero, credit or debit balance)
      accountType = getRequest();

      while ( accountType != MenuOption.END )
      {
         switch ( accountType )
         {
            case ZERO_BALANCE:
               System.out.println( "\nAccounts with zero balances:\n" );
               break;
            case CREDIT_BALANCE:
               System.out.println( "\nAccounts with credit balances:\n" );
               break;
            case DEBIT_BALANCE:
               System.out.println( "\nAccounts with debit balances:\n" );
               break;
         } // end switch

         readRecords();
         accountType = getRequest();
      } // end while
   } // end method processRequests
} // end class CreditInquiry

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