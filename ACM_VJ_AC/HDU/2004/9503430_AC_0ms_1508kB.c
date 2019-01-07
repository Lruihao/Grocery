#include<stdio.h>
int main() {
  int v;
  while (scanf("%d", &v) != EOF) {
    if (v < 0) {
      printf("Score is error!\n");
      continue;
    }
     v = v / 10;
    if (v == 9 || v == 10) {
      printf("A\n");
      continue;
    }
    if (v == 8) {
      printf("B\n");
      continue;
    }
    if (v == 7) {
      printf("C\n");
      continue;
    }
    if (v == 6) {
      printf("D\n");
      continue;
    }
    if (v >= 0 && v < 6) {
      printf("E\n");
      continue;
    }
    printf("Score is error!\n");
  }
  return 0;
}