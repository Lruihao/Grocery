#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, a[105], i;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  int x = a[0];
  int f=1;
  while (f){
    int y = 0;
	for (i = 1; i < n; i++)
		if (a[i] >= a[y])
			y = i;
	if (y == 0) f = 0;//没有比他大或等于的了
	else {
		a[0]++;
		a[y]--;
	}
  }
  printf("%d\n", a[0] - x);
  return 0;
}
