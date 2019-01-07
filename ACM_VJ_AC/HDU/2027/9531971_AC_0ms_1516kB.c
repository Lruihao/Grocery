#include<stdio.h>
#include<string.h>
int main() {
	char str[100];
	int n;
	while (scanf("%d", &n) != EOF) {
		getchar();
		int i,j,flag=0;
		char c;
		for (j = 0; j < n; j++){
			int b[5] = { 0 };
			if(flag)printf("\n");
			gets(str);
			for (i = 0; (c=str[i]) != '\0'; i++) {
				if (c == 'a')
					++b[0];
				else if (c == 'e')
					++b[1];
				else if (c == 'i')
					++b[2];
				else if (c == 'o')
					++b[3];
				else if (c == 'u')
					++b[4];
			}
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", b[0],b[1],b[2],b[3],b[4]);
			flag=1;
		}
	}
	return 0;
}