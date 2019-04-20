#include <stdio.h>
#include <string.h>
#define N 200
int main()
{
	int a[N]={0},b[N]={0},z[N]={0},i,la,lb,c=0,n;//c是进位
	int get_d(int *p);
	la=get_d(a);
	lb=get_d(b);
	n=la>lb?la:lb;
	if(n==0)printf("0");
	for(i=0;i<n;i++){
		z[n-i-1]=(a[i]+b[i]+c)%10;
		c=(a[i]+b[i]+c)/10;
	}
	if(c)printf("1");
	for(i=0;i<n;i++)
	   printf("%d",z[i]);
	return 0;
}
int get_d(int *p){
	char x[N];
	int l,i,ex=0;
	scanf("%s",x);
	l=strlen(x);
	while(x[ex]=='0')ex++;//前导0
	for(i=ex;i<l;i++)
	 *(p+l-i-1)=x[i]-'0';//倒序储存
	return l-ex;
}
