import java.util.Arrays;
import java.util.List;


public class UsingToArray {
	
	public static void main(String[] args) {
		
		String[] colors ={"black","blue", "yellow"};

		List<String> list = Arrays.asList(colors);
		list.set(1, "orange");
		
		System.out.println("colors: ");
		
		for(String color:colors)
		{
			System.out.println(color);
		}
	}
}
