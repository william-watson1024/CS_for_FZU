
public class Tclass2 extends Tclass1 {
	private String address;
	public Tclass2(String n, int a, String add) {
		super(n, a);//知识点一：通过super函数调用父类的构造函数
		setAddress(add);
		System.out.printf("\nIn Tclass2 constructor:%s", this);
	}

	public void setAddress(String address) {
		this.address = address;
	}
	
	public String getAddress() {
		return address;
	}
	
	@Override//知识点3：函数的重载方法实现
	public String toString() {
		// TODO Auto-generated method stub
		return String.format("%s, the address is %s", super.toString(), getAddress() );//知识点4，super类可以调用父类的函数
		//知识点5：String.format（）的用法
	}
	
	
	
}
