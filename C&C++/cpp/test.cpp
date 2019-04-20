#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int main()
{
    int a[]={1,3,5,7,9,2,2,2,1,1,1};
    sort(a,a+11);
    int len = unique(a,a+11)-a;
    for(int i=0;i<len;i++)
        cout<<a[i]<<" ";
    return 0;
}
