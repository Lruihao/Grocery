#include <bits/stdc++.h>
using namespace std;

int v[105];
int w[105];
int n,m,h;
int dp[205];
int main(){
    while(scanf("%d",&n)==1&&n!=0){
        int sum=0;
        scanf("%d%d",&m,&h);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&w[i],&v[i]);
        if(h==0){
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++)    //ǰi����Ʒ
                for(int j=m;j>=w[i];j--)   //ö�ٱ�������
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);  //
               sum=dp[m];
        }
        else{
             m+=h
            for(int k=1;k<=n;k++) //ö�ٿ��Ա�ʣ�µ���Ʒ
            {
                memset(dp,0,sizeof(dp));
                for(int i=1;i<=n;i++){  //ǰi����Ʒ
                    if(i!=k){
                       for(int j=m;j>=w[i];j--)   //ö�ٱ�������
                       dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                    }
                } //������һ������������ʼ������Ϊ�Ǹ�����������
               for(int j=m-1;j>=m-w[k];j--)   //ö�ٱ�������+ʣ����Ʒ
                dp[m]=max(dp[m],dp[j]+v[k]);
               // printf("%d\n",dp[m]);
               sum=max(sum,dp[m]);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
