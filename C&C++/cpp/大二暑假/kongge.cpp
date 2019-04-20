#include<stdio.h>

int main(){
    int m;
    printf("输入长度:");
    scanf("%d",&m);
    printf("输入串:");
    getchar();
    char a[20];
    gets(a);
    printf("%s",a);
    int num=0;
    for(int i=0;i<m;i++){
        if(a[i]==' ')
            num++;
    }
    printf("\n空格数为%d",num);
	return 0;
}
