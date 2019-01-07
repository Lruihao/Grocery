#include <stdio.h>

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
	{
		int i,j,t;                  
		int flag=0;                
		int a[101],b[101];         
		int c[101]={0};           
		for(i=0;i<n;i++)  
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);     

		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++){
				if(a[i]>a[j])                    
				{t=a[i];a[i]=a[j];a[j]=t;}
			}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				if(a[i]==b[j])
					break;
			if(j>=m)
				c[flag++]=a[i];
		}                        
		                        

		if(flag==0)
			printf("NULL");
		else
		{
			for(i=0;i<flag;i++)
				printf("%d ",c[i]);       
		}                       
		printf("\n");		
	}

	return 0;
}

