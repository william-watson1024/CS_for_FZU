// Fig. 19.20: WordTypeCount.java
// Program counts the number of occurrences of each word in a string
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.TreeSet;
import java.util.Scanner;

public class WordTypeCount
{
   private Map< String, Integer > map;
   private Scanner scanner;

   public WordTypeCount()
   {
      map = new HashMap< String, Integer >(); // create HashMap
      scanner = new Scanner( System.in ); // create scanner
      createMap(); // create map based on user input
      displayMap(); // display map content
   } // end WordTypeCount constructor
   
   // create map from user input
   private void createMap() 
   {
      System.out.println( "Enter a string:" ); // prompt for user input
      String input = scanner.nextLine();

      // create StringTokenizer for input
      StringTokenizer tokenizer = new StringTokenizer( input );
               
      // processing input text 
      while ( tokenizer.hasMoreTokens() ) // while more input 
      {
         String word = tokenizer.nextToken().toLowerCase(); // get word
                  
         // if the map contains the word
         if ( map.containsKey( word ) ) // is word in map
         {
            int count = map.get( word ); // get current count
            map.put( word, count + 1 );  // increment count
         } // end if
         else 
            map.put( word, 1 ); // add new word with a count of 1 to map
       } // end while
   } // end method createMap
   
   // display map content
   private void displayMap() 
   {      
      Set< String > keys = map.keySet(); // get keys

      // sort keys
      TreeSet< String > sortedKeys = new TreeSet< String >( keys );

      System.out.println( "Map contains:\nKey\t\tValue" );

      // generate output for each key in map
      for ( String key : sortedKeys )
         System.out.printf( "%-10s%10s\n", key, map.get( key ) );
      
      System.out.printf( 
         "\nsize:%d\nisEmpty:%b\n", map.size(), map.isEmpty() );
   } // end method displayMap

   public static void main( String args[] )
   {
      new WordTypeCount();
   } // end main
} // end class WordTypeCount


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
