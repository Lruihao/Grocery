#include<bits/stdc++.h>
using namespace std;

int x[55],y[55],n,s1=0,s2=0;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
        s1+=x[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&y[i]);
        s2+=y[i];
    }
    if((s1-s2)>=0)
        printf("Yes\n");
    else printf("No\n");
	return 0;
}
