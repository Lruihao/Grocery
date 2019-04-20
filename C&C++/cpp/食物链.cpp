#include<iostream>
#include<malloc.h>
using namespace std;
int N,K,D,X,Y,sum=0;

typedef struct node{
    char type;
    int date;
    struct node *next;
}node;

int main(){
    int i;
    node*head=(node*)malloc(sizeof(node));
    cin>>N>>K;
    for(i=0;i<K;i++){
        cin>>D>>X>>Y;
        if(X>D||Y>D){
            sum+=1;
            continue;
        }
        if(D==2&&X==Y){
            sum+=1;
            continue;
        }

    }
    return 0;
}
