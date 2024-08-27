import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
class Exception3{
	public static void main(String args[]){
		try{
			FileInputStream fis =new  FileInputStream("text.txt");
			int b;
			while((b=fis.read())!=-1) {
				System.out.print(b);
			}
			fis.close();
		}
		catch( IOException e ){
			System.out.println( e );
		}
		catch( FileNotFoundException e ){
			System.out.println( e );
			System.out.println("\nmessage:" +e.getMessage() );
			System.out.println();
			e.printStackTrace( System.out );
		}
		

		
	}
}
