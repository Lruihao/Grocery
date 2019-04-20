#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,a[100005],f=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    x=a[n-1];
    for(int i=0;i<n;i++)
    if(x%a[i]!=0){
        printf("No\n");
        f=1;
        break;
    }
    if(!f) printf("Yes\n");
	return 0;
}
//wa
