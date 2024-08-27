import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;



public class WordTypeCount {
	public static void main(String[] args) {
		Map<String, Integer> myMap = new HashMap<String, Integer>();
		
		createMap(myMap);
		displayMap(myMap);
	}
	
	private static void createMap(Map<String, Integer> map){
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String input = scanner.nextLine();
		
		//tokenize the input
		String[] tokens = input.split(" ");
		
		// processing input text
		for (String token : tokens) {
			String word = token.toLowerCase(); // get lowercase word
			
			if(map.containsKey(word))
			{
				int count = map.get(word); // get current count
				map.put(word, count+1);    // increment count
			}
			else
			{
				map.put(word, 1); // add new word with count of 1 to map
			}
		}	
	}
	
	private static void displayMap(Map<String, Integer> map) {
		// TODO Auto-generated method stub
		Set<String> keys = map.keySet(); // get keys
		
		// sorted keys
		TreeSet<String> sortedKeys = new TreeSet<String>(keys);
		
		System.out.println("\nMap contains:\nKey\t\tValue");
		
		//generate the ouput for each key in map
		for (String key : sortedKeys) {
			System.out.printf("%-10s%10s\n", key, map.get(key));
		}
		System.out.printf("\nsize: %d isEmpty: %b\n",map.size(),map.isEmpty());
	}
}
