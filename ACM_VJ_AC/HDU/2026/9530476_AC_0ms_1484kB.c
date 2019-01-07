#include<stdio.h>
int main() {
	char s[100];
	int i;
	char c;
	while(gets(s)){
		for (i = 0;s[i]!='\0'; i++){
			c=s[i];
			if (i == 0) {
				if (s[i]>= 97 && s[i] <= 122) {
					s[i]-= 32;
					continue;
				}
			}
			if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || (c > 90 && c < 97)  || c > 122 || c < 65) {
				if (s[i + 1] >= 97 && s[i +1]<= 122){
					s[i + 1] -= 32;
					continue;
				}
			}
		}
		for (i = 0; s[i] != '\0'; i++)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}
