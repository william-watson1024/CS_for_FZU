import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;

public class PreparedStatementTest 
{
   static final String DATABASE_URL = "jdbc:mysql://localhost/books";
   public static void main( String args[] ){
      Connection connection = null;
      PreparedStatement preparedStatement=null;
      ResultSet resultSet = null;
      try{
         connection = DriverManager.getConnection( 
			 DATABASE_URL, "username", "password" );
         preparedStatement= connection.prepareStatement("SELECT LastName,FirstName,Title "+"FROM authors "+
        		 "INNER JOIN authorisbn "+"ON authors.AuthorID=authorisbn.AuthorID "
        		 +"INNER JOIN titles "+"ON authorisbn.ISBN=titles.ISBN "
        		 +"WHERE LastName=? AND FirstName=?");
         preparedStatement.setString(1, "Deitel");
         preparedStatement.setString(2,"Paul");
         resultSet = preparedStatement.executeQuery();
         ResultSetMetaData metaData = resultSet.getMetaData();
         int numberOfColumns = metaData.getColumnCount();
         
         for ( int i = 1; i <= numberOfColumns; i++ )
            System.out.printf( "%-8s\t", metaData.getColumnName( i ) );
         System.out.println();
         while ( resultSet.next() ){
            for ( int i = 1; i <= numberOfColumns; i++ )
               System.out.printf( "%-8s\t", resultSet.getObject( i ) );
            System.out.println();
         }
      }catch ( SQLException sqlException ) {
         sqlException.printStackTrace();
      } finally {
         try {
            resultSet.close();                                      
            preparedStatement.close();
            connection.close();                                     
         }
         catch ( Exception exception ) {
            exception.printStackTrace();                            
         }
      }
   }
}
