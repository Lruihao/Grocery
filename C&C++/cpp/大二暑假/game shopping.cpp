#include<iostream>
using namespace std;

int main(){
    int n,m,s=0;
    cin>>n>>m;
    int i,j;
    int c[1000],a[1000];
    for(i=0;i<n;i++)
        cin>>c[i];
    for(i=0;i<m;i++)
        cin>>a[i];
    for(i=0,j=0;i<n;){
        if(j==m)
            break;
        if(c[i]<=a[j]){
            s++;
            j++;
            i++;
        }
        else i++;
    }
    if(i==n&&s==0)
        cout<<"0\n";
    else cout<<s<<endl;
	return 0;
}
