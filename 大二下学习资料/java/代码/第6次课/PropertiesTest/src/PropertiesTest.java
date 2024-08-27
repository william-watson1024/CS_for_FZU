// Fig. 18.19: PropertiesTest.java
// Demonstrates class Properties of the java.util package.
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;
import java.util.Set;
//properties实现了map接口，方便与io流集成
//在Java中，Properties是一个非常实用的类，它主要用于处理配置信息。它是java.util包的一部分，并且继承自Hashtable类，实现了Map接口，这意味着它是一个键值对的集合，且键和值都是字符串类型。Properties类的设计初衷是为了方便地保存和检索程序的配置信息，这些信息常常需要在不重新编译代码的情况下进行修改。
//
//主要用途：
//配置管理：应用程序通常需要一些可以在部署时或运行时调整的参数，如数据库连接字符串、系统路径等。将这些配置信息存储在.properties文件中，并使用Properties类来加载和访问它们，可以使得程序更加灵活和可维护。
//
//资源国际化：在实现软件的多语言版本时，可以通过不同的.properties文件来存储不同语言的文本资源，每个文件对应一种语言环境。
//
//特点：
//键值对结构：每个配置项由一个唯一的键和对应的值组成，键和值都是字符串类型。
//
//与IO流集成：Properties类可以方便地从输入流中加载配置信息，或者将配置信息写入输出流，便于从文件读写配置。
//
//默认值：通过getProperty方法，你可以为不存在的键提供一个默认值，这样即使配置中缺少某个键，也能保证程序的健壮性。
//
//继承自Hashtable：由于继承自Hashtable，它是一个线程安全的类，但这也意味着它的某些操作可能不是高性能的。
//
//常用方法：
//load(InputStream in)：从输入流中加载属性列表。
//store(OutputStream out, String comments)：将属性列表存储到输出流中。
//getProperty(String key)：获取指定键的属性值。
//setProperty(String key, String value)：设置属性键值对。
//clear()：清除所有属性。
public class PropertiesTest  
{
   public static void main( String[] args )
   {
      Properties table = new Properties(); // create Properties table

      // set properties
      table.setProperty( "color", "blue" );
      table.setProperty( "width", "200" );

      System.out.println( "After setting properties" );
      listProperties( table ); // display property values

      // replace property value
      table.setProperty( "color", "red" );

      System.out.println( "After replacing properties" );
      listProperties( table ); // display property values

      saveProperties( table ); // save properties

      table.clear(); // empty table

      System.out.println( "After clearing properties" );
      listProperties( table ); // display property values
      
      loadProperties( table ); // load properties

      // get value of property color
      Object value = table.getProperty( "color" );

      // check if value is in table
      if ( value != null )
         System.out.printf( "Property color's value is %s\n", value );
      else
         System.out.println( "Property color is not in table" );
   } // end main

   // save properties to a file
   private static void saveProperties( Properties props )
   {
      // save contents of table
      try
      {
         FileOutputStream output = new FileOutputStream( "props.dat" );
         props.store( output, "Sample Properties" ); // save properties
         output.close();
         System.out.println( "After saving properties" );
         listProperties( props ); // display property values
      } // end try
      catch ( IOException ioException )
      {
         ioException.printStackTrace();
      } // end catch
   } // end method saveProperties

   // load properties from a file
   private static void loadProperties( Properties props )
   {
      // load contents of table
      try
      {
         FileInputStream input = new FileInputStream( "props.dat" );
         props.load( input ); // load properties
         input.close();
         System.out.println( "After loading properties" );
         listProperties( props ); // display property values
      } // end try
      catch ( IOException ioException )
      {
         ioException.printStackTrace();
      } // end catch
   } // end method loadProperties

   // output property values
   private static void listProperties( Properties props )
   {
      Set< Object > keys = props.keySet(); // get property names
 
      // output name/value pairs
      for ( Object key : keys )
         System.out.printf( 
            "%s\t%s\n", key, props.getProperty( ( String ) key ) );

      System.out.println();
   } // end method listProperties
} // end class PropertiesTest

/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
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
