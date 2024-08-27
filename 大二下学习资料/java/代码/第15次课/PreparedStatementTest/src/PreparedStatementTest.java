import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;

public class PreparedStatementTest 
{
   // database URL                              
   static final String DATABASE_URL = "jdbc:mysql://localhost/books?useUnicode = true & characterEncoding = utf-8 & useSSL = false & &serverTimezone = GMT";
   // launch the application
   public static void main( String args[] )
   {
      Connection connection = null; // manages connection
      PreparedStatement authorBooks=null;
      ResultSet resultSet = null; // manages results
    
      // connect to database books and query database
      try 
      {
         // establish connection to database                              
         connection = DriverManager.getConnection( 
			 DATABASE_URL, "deitel", "deitel" );

         // create Statement for querying database
         authorBooks= connection.prepareStatement("SELECT LastName,FirstName,Title "+"FROM authors "+
        		 "INNER JOIN authorisbn "+"ON authors.AuthorID=authorisbn.AuthorID "
        		 +"INNER JOIN titles "+"ON authorisbn.ISBN=titles.ISBN "
        		 +"WHERE LastName=? AND FirstName=?");
         
         // query database
         authorBooks.setString(1, "Deitel");
         authorBooks.setString(2,"Paul");
         resultSet = authorBooks.executeQuery();
         
         // process query results
         ResultSetMetaData metaData = resultSet.getMetaData();
         int numberOfColumns = metaData.getColumnCount();     
         System.out.println( "The result of the query:\n" );
         
         for ( int i = 1; i <= numberOfColumns; i++ )
            System.out.printf( "%-8s\t", metaData.getColumnName( i ) );
         System.out.println();
         
         while ( resultSet.next() ) 
         {
            for ( int i = 1; i <= numberOfColumns; i++ )
               System.out.printf( "%-8s\t", resultSet.getObject( i ) );
            System.out.println();
         } // end while
      }  // end try
      catch ( SQLException sqlException )                                
      {                                                                  
         sqlException.printStackTrace();
      } // end catch                                                     
      finally // ensure resultSet, statement and connection are closed
      {                                                             
         try                                                        
         {                                                          
            resultSet.close();                                      
            authorBooks.close();                                      
            connection.close();                                     
         } // end try                                               
         catch ( Exception exception )                              
         {                                                          
            exception.printStackTrace();                            
         } // end catch                                             
      } // end finally                                              
   } // end main
} // end class DisplayAuthors
