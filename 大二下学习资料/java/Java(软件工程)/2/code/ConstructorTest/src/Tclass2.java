
public class Tclass2 extends Tclass1 {
	private String address;
	public Tclass2(String n, int a, String add) {
		super(n, a);
		setAddress(add);
		System.out.printf("\nIn Tclass2 constructor:%s", this);
	}

	public void setAddress(String address) {
		this.address = address;
	}
	
	public String getAddress() {
		return address;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return String.format("%s, the address is %s", super.toString(), getAddress() );
	}
	
	
	
}
