
import java.sql.*;

public class SQL {
    public static void main(String []args)throws Exception{
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection connection= DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase","username","password");
        Statement statement=connection.createStatement();
        String sql="";
        ResultSet resultSet=statement.executeQuery(sql);
        ResultSetMetaData metaData=resultSet.getMetaData();
        int numOfColumns=metaData.getColumnCount();
        for (int i=1;i<=numOfColumns;i++){
            System.out.printf("%-8s\t",metaData.getColumnName(i));
        }

        while (resultSet.next()){
            for (int i=1;i<=numOfColumns;i++){
                System.out.printf("%-8s\t",resultSet.getObject(i));
            }
        }
        try{
        resultSet.close();
        statement.close();
        connection.close();
        }catch (Exception e){
            e.printStackTrace();
        }

    }
}
