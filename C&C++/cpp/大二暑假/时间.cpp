#include<bits/stdc++.h>
using namespace std;

int main(){
    int x[16][2];//打表知道只有16个一共
    int a,b;
    int i,j,k=0;
    memset(x,0,sizeof(x));
    for(i=0;i<24;i++)
        for(j=0;j<60;j++)
            if(i==j%10*10+j/10) {x[k][0]=i;x[k++][1]=j;/*cout<<i<<":"<<j<<endl;*/}

    while(scanf("%d:%d",&a,&b)!=EOF){
        if(a==0&&b==0) {cout<<"23:32"<<endl;cout<<"1:10"<<endl;continue;}
        if(a==23&&b==32) {cout<<"22:22"<<endl;cout<<"0:0"<<endl;continue;}
        for(i=1;i<16;i++)
            if((a*60+b)<(x[i][0]*60+x[i][1])){
                cout<<x[i-1][0]<<":"<<x[i-1][1];
                cout<<x[i][0]<<":"<<x[i][1];
                break;
            }
    }
	return 0;
}


