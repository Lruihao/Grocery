#include<stdio.h>
#include<string.h>
int const MAX = 5e6 + 5;
char s1[MAX], s2[MAX], ans[MAX];
int next[MAX], pos[MAX];
int l1, l2, cnt;

void get_next()
{
    int i = 0, j = -1;
    next[0] = -1;
    while(s2[i] != '\0')
    {
        if(j == -1 || s2[i] == s2[j])
        {
            i ++;
            j ++;
            if(s2[i] == s2[j])
                next[i] = next[j];
            else
                next[i] = j;
        }
        else
            j = next[j];
    }
}

void KMP()
{
    get_next();
    int i = 0, j = 0;
    cnt = 0;
    while(s1[i] != '\0')
    {
        ans[cnt] = s1[i ++];
        while(!(j == -1 || ans[cnt] == s2[j]))
            j = next[j];
        j ++;
        cnt ++;
        pos[cnt] = j;
        if(j == l2)
        {
            cnt -= l2;
            j = pos[cnt];
        }
    }
}

int main()
{
    while(scanf("%s %s", s2, s1) != EOF)
    {
        l1 = strlen(s1);
        l2 = strlen(s2);
        KMP();
        for(int i = 0; i < cnt; i++)
            printf("%c", ans[i]);
        printf("\n");
    }
}    