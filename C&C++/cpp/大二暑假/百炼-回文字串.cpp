#include<stdio.h>
#include<string.h>
int main()
{
    char a[505];
    int n,len,begin,maxBegin,i,j;
    scanf("%s",a);
    n=strlen(a);
    for(len=2;len<=n;len++)//ö���Ӵ������п��ܵĳ���
    {
        maxBegin=n-len;
        for(begin=0;begin<=maxBegin;begin++)//ö���Ӵ��Ŀ�ʼ��
        {
            j=begin+len-1;
            for(i=begin;i<j;i++,j--) //������ǰ�Ӵ���a[i]~a[begin+len-1]��,�ж��Ƿ���Ĵ�
            {
                if(a[i]!=a[j]) break;
            }
            if(i>=j)//�ǻ��Ĵ�
            {
                j=begin+len-1;
                for(i=begin;i<=j;i++) printf("%c",a[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
/*
1��ö���Ӵ������п��ܵĳ��� for(len=2;len<=n;len++)
2��������ȷ��Ϊlenʱ��ö�����г���Ϊlen���Ӵ��Ŀ�ʼ�㡣
        maxBegin=n-len;
        for(begin=0;begin<=maxBegin;begin++)
3������ʼ��ͳ�����ȷʱ�����Ա������Ӵ����ж����Ƿ���Ĵ���
            j=begin+len-1;
            for(i=begin;i<j;i++,j--)
*/
