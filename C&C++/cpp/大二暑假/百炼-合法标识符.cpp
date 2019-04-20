#include <stdio.h>
#include <string.h>
int main()
{
	char c,s[20];
	int i,j,f;
    gets(s);
    f=0;
    for(i=0;(c=s[i])!='\0';i++)
        if(c==' '||c<48||c>=58&&c<=64||c>90&&c<95||c>122||c==96)
            f=1;
    if(s[0]>='0'&&s[0]<='9'||f!=0)
        printf("no\n");
    else
        printf("yes\n");
	return 0;
}
