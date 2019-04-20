#include <stdio.h>
#include <windows.h>     //system("cls")清屏函数
#define size 50

struct stacks {
	int data[size];
	int top;
} stack;


void bag(){
    int w[size];//体积
	int V;
	int i = 0;
	int j = 0;
	int number;
	printf("\t**简单背包问题**\n\n");
	printf("\n请输入物品的个数：\n");
	scanf("%d", &number);
	printf("\n请输入各件物品的体积：\n");
	for (i = 0; i < number; i++)
		scanf("%d", &w[i]);

	//排序，利用异或运算简单选择排序（异或两次其值不变）
	for(i=0;i<number;i++)
		for(j=i+1;j<number;j++)
			if(w[i]>w[j]){
				w[i]=w[i]^w[j];
				w[j]=w[i]^w[j];
				w[i]=w[i]^w[j];
			}

	printf("\n请输入背包的总体积：\n");
	scanf("%d", &V);
	getchar();    //吸收回车
	while(V <= 0){
		printf("输入背包体积错误！重新输入！\n");
		scanf("%d",&V);
		getchar();
	}

	//预处理
	int s = 0;
	for (i = 0; i < number; i++)
		s = s + w[i];
	if(V > s){
		printf("背包无解！\n");
		printf("任意键返回主菜单！\n");
        getchar(); //延时效果，顺便吸收任意键
        system("cls");
		return;
	}
	if(V==s){
		printf("只有一个符合条件的解：");
		for (i = 0; i < number; i++)
            printf("%d ",w[i]);
        printf("\n");
        printf("任意键返回主菜单！\n");
        getchar();
        system("cls");
		return;
	}

	//初始化栈
	for (i = 0; i < number; i++)
        stack.data[i] = 0;
	stack.top = 0;

    j=1;
    int k=0;
    int flag=0;
    do {
		while (V > 0 && k <= number) {
			if (V >= w[k]) {
				stack.data[stack.top] = k;//第k个物品的体积下标
				stack.top++;
				V -= w[k];
			}
			k++;
		}

		if (V == 0) {
			flag=1;
			printf("第%d个符合条件的解：", j);
			for (i = 0; i < stack.top; i++) {
				printf("%d ", w[stack.data[i]]);
			}
			j++;
			printf("\n");
		}
		//k满时回溯
		k = stack.data[--stack.top];
		stack.data[stack.top] = 0;
		V += w[k];
		k++;
	} while (!(stack.top == 0 && k == number));
	if(!flag){
		printf("背包无解！\n");
	}

	printf("任意键返回主菜单！\n");
	getchar();
	system("cls");
}

void bag01(){

    int m[size][101] = {{0}},n,i,j,T;
    int w[size]={0};  //价值
    int v[size]={0}; //物体体积
    printf("\t**01背包问题**\n\n");
    printf("请输入物品的个数：\n");
    scanf("%d",&n);
    printf("请输入各个物品的体积：\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("请输入各个物品的价值：\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("请输入背包的总体积：\n");
    scanf("%d",&T);
    getchar();
    while(T <= 0){
		printf("输入背包体积错误！重新输入！\n");
		scanf("%d",&T);
		getchar();
	}
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=T; j++)
        {                           //状态方程，判定是否装入，
            if(j<v[i])
                m[i][j] = m[i-1][j];
            else
                m[i][j] = m[i-1][j]>(m[i-1][j-v[i]] + w[i])?m[i-1][j]:(m[i-1][j-v[i]] + w[i]);
            //printf("%d ",m[i][j]);  //动态规划过程打表
        }
        //printf("\n");
    }
    printf("背包能带走的最大价值为：\n");
    printf("%d\n",m[n][T]);

    printf("任意键返回主菜单！\n");
	getchar();
	system("cls");
}

int main() {
    int i=0,f=0;//f为序号错误的标志
    while(i!=3){
    printf("\t**背包问题**\n\n");
    printf("\t-->1.简单背包\n");
    printf("\t-->2.01背包\n");
    printf("\t-->3.退出\n\n");
    printf("输入序号：\n");
    while(!f){
    scanf("%d",&i);
    switch(i){
        case 1: system("cls");bag();f=1;break;
        case 2: system("cls");bag01();f=1;break;
        case 3: f=1;break;
        default: printf("序号错误，请重输！\n");f=0;break;
    }
    }
    f=0;
    }
	return 0;
}

