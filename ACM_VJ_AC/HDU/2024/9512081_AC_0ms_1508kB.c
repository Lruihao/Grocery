#include<stdio.h>
int main(){
	int n,i,lag;
	char a[50];
	scanf("%d",&n);
		getchar();
		while(n--){
			lag=0;
			gets(a); 
			if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')|| a[0]=='_'){
				for(i=1;a[i]!='\0';i++){
					if((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')|| a[i]=='_' || (a[i]>='0' && a[i]<='9'))
					  lag=1;
					else{
						lag=2;
						break;
					}
				}
				if(lag==1)
				  printf("yes\n");
				else
				  printf("no\n");
			}else{
			  printf("no\n");	
			} 
		}
	return 0;
}