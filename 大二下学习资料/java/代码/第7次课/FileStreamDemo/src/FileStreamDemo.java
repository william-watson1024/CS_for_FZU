import java.io.*;

public class FileStreamDemo {
	public static void main(String[] args)
	{
		String file1,file2 ;
		int ch = 0 ;
		file1 = "第7次课/FileStreamDemo/file1.txt";
		file2="file2.txt";
		try
		{
			//创建输入输出流
			FileInputStream fis = new FileInputStream(file1);
			FileOutputStream fos=new FileOutputStream(file2);
			
			int size=fis.available();
			System.out.println("字节有效数："+size);
			
			//进行文件拷贝
			while ((ch=fis.read())!=-1)
			{
				fos.write(ch);
			}
			fis.close();
			fos.close();
		}
		catch (IOException e)
		{
			System.out.println(e.toString());
		} 
	}
}
