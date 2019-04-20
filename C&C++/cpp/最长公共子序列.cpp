#include<iostream>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
char a[1000],b[1000];
int f[1001][1001];
int re;
int main(){
    int lena, lenb,i,j,re;
    while(cin>>a>>b)
    {
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0; i<=lena; i++)
            f[i][0]=0;
        for(j=0; j<=lenb; j++)
            f[0][j]=0;
        for(i=1; i<=lena; i++)
            for(j=1;j<=lenb; j++)
                if(a[i-1]==b[j-1])
                    f[i][j]=f[i-1][j-1]+1;
                else
                    f[i][j]=MAX(f[i-1][j],f[i][j-1]);
        cout<<f[lena][lenb]<<endl;
    }
    return 0;
}
