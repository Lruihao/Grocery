package jicheng;

class Fu {
	static {
		System.out.println("父类静态代码块");
	}

	{
		System.out.println("父类构造代码块");
	}

	public Fu() {
		System.out.println("父类构造方法");
	}
}

class Zi extends Fu {
	static {
		System.out.println("子类静态代码块");
	}

	{
		System.out.println("子类构造代码块");
	}

	public Zi() {
		System.out.println("子类构造方法");
	}
}


public class test {
	public static void main(String[] args) {
		Zi z = new Zi();
		Zi z2 = new Zi();
	}
}
