package caishuzi;

import java.util.Scanner;

class Num {
	private int[] a= {0,0,0,0};
	
	public Num() {}
	
	public void setx() {
		/*for(int i=0;i<4;i++) {
			a[i]=(int)(Math.random()*10);
		}*/
		//为了四个互不相同的随机数
		a[0]=(int)Math.random()*10+1;
		for(int i=1;i<4;i++) {
			int t=(int)(Math.random()*10);
			for(int j=0;j<i;j++) {
				if(t==a[j]) {
					t=(int)(Math.random()*10);
					j=0;
				}
			}
			a[i]=t;
		}	
	}
	public int[] getx() {
		return a;
	}
	public void show() {
		System.out.println();
		for(int i=0;i<4;i++)
			System.out.print(a[i]+" ");
		System.out.println();
	}
	
}

public class caishuzi {
	
	public static void main(String agrs[]) {
		int a[] = {0,0,0,0},b[] = {0,0,0,0};
		System.out.println("* * * *\n请输入4个数字！A表示位置数字都正确，B表示数字正确位置错误。");
		Scanner sc=new Scanner(System.in);
		Num n=new Num();
		n.setx();
		a=n.getx();
		/*for(int i=0;i<4;i++)
			System.out.print(a[i]+" ");
		n.show();*/
		for(int k=0;k<10;k++) {//猜测次数
			int A=0,B=0,C=0;
			for(int i=0;i<4;i++) {
				b[i]=sc.nextInt();
			}
			sc.close();
			for(int i=0;i<4;i++){
				if (b[i]==a[i])A++;
				for(int j=0;j<4;j++){
					C=b[i]==a[j]?++C:C;//C表示猜测数内和随机数中A类和B类数的数目
					if (b[i]==a[j])break;
				}
			}
			B=C-A;// 关键算法
			if(A==4) {
				System.out.println("恭喜猜对啦！");
			}else {
				System.out.println(A+"A"+B+"B");
			}
		}
		
	}

}
