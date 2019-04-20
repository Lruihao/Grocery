#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef struct node{
    int age;
    string name;
    double num;
}node;
bool cmp(node a,node b){
    if(a.num!=b.num)return a.num>b.num;
    if(a.name!=b.name)return a.name<b.name;
    return a.num<b.num;
}
int main()
{
    node aa[3]={{18,"li",95},{18,"zhang",95},{20,"wang",100}};
    sort(aa,aa+3,cmp);
    for(int i=0;i<3;i++)
    cout<<aa[i].name<<" "<<aa[i].age<<" "<<aa[i].num<<endl;
    return 0;
}
