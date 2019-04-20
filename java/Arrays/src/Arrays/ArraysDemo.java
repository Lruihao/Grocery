package Arrays;

import java.text.Collator;
import java.util.Arrays;
import java.util.Comparator;

public class ArraysDemo {
	public static void main(String agrs[]) {
		Integer arr[]=new Integer[9];
		for(int i=0;i<9;i++)
			arr[i]=(int)(Math.random()*100);
		//显示，排序数组
		System.out.print("原内容：");
		display(arr);
		Arrays.sort(arr);
		System.out.print("排序后：");
		display(arr);
		//将值-1分配给数组arr中下标从0到3-1的位置
		Arrays.fill(arr, 0,3,-1);
		System.out.print("fill()后：");
		display(arr);
		//搜索23
		System.out.print("值23的位置：");
		int index =Arrays.binarySearch(arr, 23);//二分查找
		System.out.print(index);//如果查找不到，index为负
		System.out.print("\n插入0在3号位置：");
		Arrays.fill(arr,3,4,0);
		display(arr);
		System.out.print("值0的位置：");
		index =Arrays.binarySearch(arr, 0);
		System.out.print(index);
		Integer arr2[]=new Integer[8];
		arr2=Arrays.copyOf(arr, arr2.length);
		//复制8个
		System.out.print("\n复制后的数组：");
		display(arr2);
		if(Arrays.equals(arr, arr2))
			System.out.println("两数组相同！");
		else System.out.println("两数组不相同！");
		System.out.println("----------------------------------------");
		String[] str = {"计算机","黄桑","通信","李瑞豪"};
		Arrays.sort(str);
		for(int i=0;i<str.length;i++)
			System.out.print(str[i]+" ");
		System.out.println("");
		//Collator类是用来执行分语言环境的字符串比较，这里用的CHINA
		Comparator com=Collator.getInstance(java.util.Locale.CHINA);//获取Comparator对象，参数表示按中文排序
		//根据指定的 "比较器" 产生的顺序对 "指定对象数组" 进行排序
		Arrays.sort(str,com);//sort(T[] a,Comparator<?super T>c)
		for(int i=0;i<str.length;i++)
			System.out.print(str[i]+" ");
	}
	static void display(Integer arr[]) {
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println("");
	}
}
