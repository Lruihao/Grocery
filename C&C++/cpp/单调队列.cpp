#include<cstdio>
#define pd (!x&&f[tail-1]>a[i])||(x&&f[tail-1]<a[i])
using namespace std;
int n,k,head,tail;
int a[1000001],f[1000001],t[1000001];


void getmaxmin(int x){
    head=tail=0;
    for(int i=0;i<n;i++){
        while(head<tail&&(pd))tail--;
        //求最小值那么就从尾部开始删除比他大的值
        //求最大值那么就从尾部删除比他小的值
        f[tail]=a[i];
        t[tail]=i;//记录当前认为最小值的下标（位置）
        tail++;
        while(t[head]<=i-k)head++;
        //当前i的位置向左移滑框的距离，其中不包括当前最小值的位置
            //保证队首元素在滑窗之内,不在滑窗内那么就说明滑窗已经移动到后面了，那么这个时候，就要把首指针右移，当前首指针指的值不在新的滑窗范围之内
        if(i>k-2)
            printf("%d%c",f[head],i == n - 1 ? '\n' : ' ');
    }
}


int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    getmaxmin(0);//单增队列维护最小值
    getmaxmin(1);//单减队列维护最大值
}
}
