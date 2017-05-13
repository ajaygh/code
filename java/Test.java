class FreshJuice{
	enum Size{SMALL, MEDIUM, LARGE}
	Size size;
}

public class Test{
	public static void main(String []args){
		FreshJuice fj = new FreshJuice();
			fj.size = FreshJuice.Size.LARGE;
		System.out.println("Fresh juice size: "+ fj.size);
	}
}
