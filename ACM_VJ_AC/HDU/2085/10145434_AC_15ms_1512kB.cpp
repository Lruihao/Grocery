#include<stdio.h>
int main (){
    __int64 H[34] = { 1 , 3 },L[34] = { 0 , 1 };
    for ( int i = 2; i != 34; ++ i ){
          H[i] = 3 * H[i-1] + 2 * L[i-1];
          L[i] = H[i-1] + L[i-1]; 
    }
    int N;
    while (scanf("%d",&N) , N + 1 )
		printf("%I64d, %I64d\n",H[N],L[N]);
    return 0; 
}