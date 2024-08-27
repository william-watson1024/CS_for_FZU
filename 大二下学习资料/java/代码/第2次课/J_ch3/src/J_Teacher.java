//类的继承
class J_Employee
{
	public int m_workyear ; //工作年限
	
	public J_Employee() {
		// TODO Auto-generated constructor stub
		m_workyear = 1; 
	}
	
}

public class J_Teacher extends J_Employee {
	
	public int m_classHour; 
	
	public J_Teacher() {
		// TODO Auto-generated constructor stub
		m_classHour = 96;
	}
	
	public void mb_printInfo()
	{
		System.out.println("该教师的工作年限为 " + m_workyear);
		System.out.println("该教师的授课课时为" + m_classHour);
	}
	
	public static void main(String[] args) {
		J_Teacher teacher = new J_Teacher();
		teacher.mb_printInfo();
	}
}
