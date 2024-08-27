
public class J_Student {
	public int m_id; 
	public int m_age; 
	
	public J_Student() {
		// TODO Auto-generated constructor stub
		mb_setData(200231123, 19);
	}
	
	public J_Student(int id, int age) {
		// TODO Auto-generated constructor stub
		mb_setData(id, age);
	}
	
	public void mb_setData (int id, int age)
	{
		m_id = id ; 
		m_age = age;
	}
	
	public void mb_setData (int id)
	{
		m_id = id ; 
	}
	
	public static void main(String[] args) {
		J_Student jack = new J_Student();
		jack.mb_setData(22222222);
		J_Student lisa = new J_Student();
		lisa.mb_setData(11111111, 18);
		System.out.print("Jack的学号是 " + jack.m_id);
		System.out.println("年龄是 " + jack.m_age);
		System.out.print("lisa的学号是 " + lisa.m_id);
		System.out.println("年龄是 " + lisa.m_age);
	}
	
}
