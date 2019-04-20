#include<bits/stdc++.h>
using namespace std;


/*int main(){
    int i,j,cnt=0;
    long long c[11][11],sum=0,sum1=0;
    for(i = 0; i < 11; i++){//Ñî»ÔÈý½Ç
        c[i][0] = 1;
        c[i][i] = 1;
        for(j = 1; j < i; j++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    string a,b;
    cin>>a>>b;
    //cout<<a<<endl<<b<<endl;
    int len=a.length();
    for(i=0;i<len;i++)
        if(a[i]=='+') sum+=1;
        else sum-=1;
    for(i=0;i<b.length();i++){
        if(b[i]=='+') sum1+=1;
        else if(b[i]=='-')sum1-=1;
        if(b[i]=='?') cnt++;
    }
    if(sum==sum1&&cnt==0){
        printf("1.000000000000\n");
        return 0;
    }
    int flag=0;
    long long x=0;
    for(j=0;j<=cnt;j++)
        x+=c[cnt][j];
        //cout<<x<<endl;
    for(i=0;i<=cnt;i++)
        if(cnt-2*i+sum1==sum){
            flag=1;
            long double y=c[cnt][i]*1.0/x;
            printf("%.12llf\n",y);
        }
    if(!flag)printf("0.000000000000\n");
	return 0;
}*/

int main(){
    string a,b;
    int  x,y,z,p,q,c[11][11],i,j;
    for(i = 0; i < 11; i++){//Ñî»ÔÈý½Ç
        c[i][0] = 1;
        c[i][i] = 1;
        for(j = 1; j < i; j++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    cin>>a;
    cin>>b;
    x=y=z=p=q=0;
    for(i=0;i<a.length();i++)
        if(a[i]=='+') x++;
        else y++;
    for(i=0;i<b.length();i++){
        if(b[i]=='+') p++;
        else if(b[i]=='-') q++;
        else z++;
    }
    if(x==p&&z==0){
        printf("1.000000000000\n");
        return 0;
    }
    if(x-p<0||y-q<0) {
        printf("0.000000000000\n");
        return 0;
    }
    x=x-p;
    printf("%0.12f",c[z][x]*1.0/(2<<(z-1)));
    return 0;
}
