#include<cstdio>
#define pd (!x&&f[tail-1]>a[i])||(x&&f[tail-1]<a[i])
using namespace std;
int n,k,head,tail;
int a[1000001],f[1000001],t[1000001];


void getmaxmin(int x){
    head=tail=0;
    for(int i=0;i<n;i++){
        while(head<tail&&(pd))tail--;
        //����Сֵ��ô�ʹ�β����ʼɾ���������ֵ
        //�����ֵ��ô�ʹ�β��ɾ������С��ֵ
        f[tail]=a[i];
        t[tail]=i;//��¼��ǰ��Ϊ��Сֵ���±꣨λ�ã�
        tail++;
        while(t[head]<=i-k)head++;
        //��ǰi��λ�������ƻ���ľ��룬���в�������ǰ��Сֵ��λ��
            //��֤����Ԫ���ڻ���֮��,���ڻ�������ô��˵�������Ѿ��ƶ��������ˣ���ô���ʱ�򣬾�Ҫ����ָ�����ƣ���ǰ��ָ��ָ��ֵ�����µĻ�����Χ֮��
        if(i>k-2)
            printf("%d%c",f[head],i == n - 1 ? '\n' : ' ');
    }
}


int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    getmaxmin(0);//��������ά����Сֵ
    getmaxmin(1);//��������ά�����ֵ
}
}
