#include<stdio.h>

int main(){
    int m;
    printf("���볤��:");
    scanf("%d",&m);
    printf("���봮:");
    getchar();
    char a[20];
    gets(a);
    printf("%s",a);
    int num=0;
    for(int i=0;i<m;i++){
        if(a[i]==' ')
            num++;
    }
    printf("\n�ո���Ϊ%d",num);
	return 0;
}
