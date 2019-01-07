#include<stdio.h>
int main() {
  int a[12]={31,0,31,30,31,30,31,31,30,31,30,31},y,m,d,i,s=0;
  while(scanf("%d/%d/%d",&y,&m,&d)!=EOF){
  if(y%4==0&&y%100!=0||y%400==0)
  a[1]=29;
  else a[1]=28;
  for(i=0;i<m-1;i++)
    s+=a[i];
  s+=d;
  printf("%d\n",s);
  s=0;
  }
  return 0;
}