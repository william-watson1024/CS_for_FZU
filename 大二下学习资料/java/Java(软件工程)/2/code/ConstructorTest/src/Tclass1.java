
public class Tclass1 {
	private String name;
	private int age ;
	public Tclass1(String n, int a) {
		// TODO Auto-generated constructor stub
		name = n ; 
		age = a ;
		System.out.printf("\nIn Tclass1 constructor: %s", this);
	}
	public int getAge() {
		return age;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return String.format("\nThe name is %s,  the age is %d ", getName(), getAge());
	}
	
}
