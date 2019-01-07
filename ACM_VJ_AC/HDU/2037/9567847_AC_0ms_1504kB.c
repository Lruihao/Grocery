#include<stdio.h>
int main()
{
	int n,size[100][2],i,j,ex1,ex2,count,began;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(i=0;i<n;i++)
		for(j=0;j<2;j++)
		scanf("%d",&size[i][j]);
		for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		if(size[i][1]>size[j][1])
		{
			ex1=size[i][0];ex2=size[i][1];
			size[i][0]=size[j][0];size[i][1]=size[j][1];
			size[j][0]=ex1;size[j][1]=ex2;
		}
		for(count=0,i=0,began=0;i<n;i++)
		if(size[i][0]>=began)
		{
			began=size[i][1];
			count++;
		}
		
		printf("%d\n",count);
	}
	return 0;
}