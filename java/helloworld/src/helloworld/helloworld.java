package helloworld;

import java.util.Scanner;

public class helloworld {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i=sc.nextInt(),j=sc.nextInt(),k=sc.nextInt();
		sc.close();
		System.out.println(i+"+"+j+"="+(i+j));
		System.out.println("MAXij="+Max(i,j));
		System.out.println("MAXijk="+Max(i,j,k));

	}
	static int Max(int i,int j) {
		return i>j?i:j;
	}
	static int Max(int i,int j,int k) {	
		if(i==j)
			System.out.println("i和j相等");
		else if(i==k)
			System.out.println("i和k相等");
		else if(j==k)
			System.out.println("j和k相等");
		return  (i=i>j?i:j)>k?i:k;
	}

}
