#include<stdio.h>
#include<stdlib.h>
void Merge(int A[],int Temp[],int L,int R,int RightEnd)//合并两个有序序列
{
    int LeftEnd=R-1;
    int p=L,i;
    int num=RightEnd-L+1;
    while(L<=LeftEnd&&R<=RightEnd)
        if(A[L]<=A[R])
            Temp[p++]=A[L++];
        else
            Temp[p++]=A[R++];
    while(L<=LeftEnd)
        Temp[p++]=A[L++];
    while(R<=RightEnd)
        Temp[p++]=A[R++];
    for(i=0;i<num;i++,RightEnd--)
        A[RightEnd]=Temp[RightEnd];
}
void MSort(int A[],int Temp[],int L,int RightEnd)
{
    int center;
    if(L<RightEnd)
    {
        center=(L+RightEnd)/2;
        MSort(A,Temp,L,center);
        MSort(A,Temp,center+1,RightEnd);
        Merge(A,Temp,L,center+1,RightEnd);
    }
}
void Merge_sort(int A[],int N)
{
    int *Temp=(int *)malloc(N*sizeof(int));
    if(Temp)
    {
        MSort(A,Temp,0,N-1);
        free(Temp);
    }
    else
        printf("no space!\n");
}
int main(){
    int A[10];
    for(int i=0;i<10;i++)
        scanf("%d",&A[i]);
    printf("Previous Arrary:");
    for(int i=0;i<9;++i)
        printf(" %d",A[i]);
    Merge_sort(A,9);
    printf("\nSorted Arrary:");
    for(int i=0;i<9;++i)
        printf(" %d",A[i]);
    printf("\n");
    return 0;
}
