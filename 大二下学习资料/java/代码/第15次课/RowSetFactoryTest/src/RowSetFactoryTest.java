
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

import javax.sql.rowset.JdbcRowSet;
import javax.sql.rowset.RowSetFactory;
import javax.sql.rowset.RowSetProvider;


public class RowSetFactoryTest {
  
    private String url= "jdbc:mysql://localhost/books?useUnicode = true & characterEncoding = utf-8 & useSSL = false & &serverTimezone = GMT";
    private String user = "root";
    private String pass = "123456";
 
    
    public void update(String sql) throws SQLException {
        RowSetFactory factory = RowSetProvider.newFactory();
        
        try (
                //使用RowSet的execute方式返回数据，则不再需DriverManager连接数据库了
                //Connection conn = DriverManager.getConnection(url, user, pass);
                /*
                 * for JDK1.6
                 * JdbcRowSet jdbcRs = new JdbcRowSetImpl(conn);
                 */
                // for JDK 1.7
                JdbcRowSet jdbcRs = factory.createJdbcRowSet();
                 ) {
            jdbcRs.setUrl(url);
            jdbcRs.setUsername(user);
            jdbcRs.setPassword(pass);
            jdbcRs.setCommand("SELECT * FROM authors");
            jdbcRs.execute();
            
            jdbcRs.afterLast();
            //向前滚动结果集
            while(jdbcRs.previous()) {
                System.out.println(jdbcRs.getInt(1)+"\t"+jdbcRs.getString(2)+"\t"+jdbcRs.getString(3));
                
               
                
            }
        }
    }
    
    public static void main(String[] args) throws FileNotFoundException, ClassNotFoundException, IOException, SQLException {
        RowSetFactoryTest jt = new RowSetFactoryTest();
  
        jt.update("select * from books");
    }
}