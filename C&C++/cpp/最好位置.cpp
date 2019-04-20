#include<cstdio>
#include<cstring>
int main(){
    char a[200005],b[200005];
    int la,lb;
    scanf("%s%s",a,b);
    la=strlen(a);lb=strlen(b);
    for(int i=0;i<la;)
        for(int j=0;j<lb&&i<la;j++,i++)
            if(a[i]!=b[j]){
                printf("No\n");
                return 0;
            }
    printf("Yes\n");
    return 0;
}
