#include<stdio.h>
#include<string.h>
#define N 200
int get_d(int *p) {
  char x[N];
  int l, i, ex = 0;
  scanf("%s", x);
  l = strlen(x);
  while (x[ex] == '0')//前导0
    ex++;
  for (i = ex; i < l; i++)
    *(p + l - i - 1) = x[i] - '0';
  return l - ex;
}
int main() {
  int a[N] = {0},b[N]={0},c[N]={0},i,la,lb;
  la = get_d(a);
  lb = get_d(b);
  for(i=0;i<la;i++){
     if (a[i]==-1){a[i]=9;a[i+1]--;}//本身为0，被借位
     if (a[i]>=b[i])
        c[i]=a[i]-b[i];
     if (a[i]<b[i]){
        c[i]=a[i]+10-b[i];
        a[i+1]--;
     }
  }
  if (c[la-1])printf("%d",c[la-1]);
  for (i=la-2;i>=0;i--)
     printf("%d",c[i]);
  return 0;
}
