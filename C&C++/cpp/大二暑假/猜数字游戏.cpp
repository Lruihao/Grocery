#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
//↓定义系统获取随机数的函数
void get_x(int *p){
  int i, j;
  int x[4];
  srand(time(0));//此函数提供种子，即time(0)系统时间秒数。这让rand()函数提供的数字每秒都不一样
  x[0] = rand() % 10;
  for (i = 1; i < 4; i++) {
  Lab:x[i] = rand() % 10;
    for (j = 0; j < i; j++) {
      if (x[i] == x[j])
        goto Lab;
    }
  }
  for (i=0;i<4;i++)
      *(p+i)=x[i];

  /*for (i=0;i<4;i++)
      printf("%d ",x[i]);*/	//注释部分在测试时可以用到，用于输出生成的4位随机数。
    for (i=0;i<4;i++)
      printf("* ");
  printf("\n\n");
}

//↓定义用户输入函数
void yhsr(int *q){
	lab:printf("请连续输入4个互不相同的数字！\n");
	int i,j,y[4];
	for (i = 0; i < 4; i++) {
		y[i]=getch()-'0';
		printf("*");
	}
	for (i = 1; i < 4; i++)
    for (j = 0; j < i; j++) {
      if (y[i] == y[j])
      goto lab;
    }
  for (i = 0; i < 4; i++)
    *(q + i) = y[i];

  /*for (i=0;i<4;i++)
      printf("%d ",y[i]);*/ //注释部分在测试时可以用到，用于输出生成的4位随机数。
  printf("\n\n");
}

void help(){
	printf("帮助\n\n该游戏可以由程序随机产生或由用户输入四个0到9之间的数字，且不重复。\n");
	printf("玩游戏者通过游戏提示输入八次来匹配上面所输入的数字。\n");
	printf("A表示位置正确且数字正确，B表示数字正确而位置不正确。\n作者：李瑞豪\n\n");
}
void clan(){
	system("cls");
	printf("感谢使用本程序！\n");
}

int main(){
	int a[4],b[4],i,j,k,n=11,A,B,C,flag,flag1,star;

	//↓主菜单
	menu:
    system("cls");
	printf("\t猜数字游戏\n1.随机产生数据\n2.用户输入数据\n3.帮助\n4.退出游戏\n");
	printf("请输入你的选择并按回车键进入\n");
	shuru:scanf("%d",&star);
    if(star==1){system("cls");again1:get_x(a);star=1;}
    if(star==2){system("cls");again2:yhsr(a);star=2;}
	if(star==3){
        system("cls");
		help();
		printf("输入任意键返回主菜单\n");
		getch();
		if(1)goto menu;
	}
	if(star==4)goto over;
	if(star!=1&&star!=2&&star!=3&&star!=4){
		printf("输入错误，请重新输入！\n");
		goto shuru;
	}
	star=0;

	printf("请输入数字，空格隔开!\n");
	for(k=0;k<8;k++){
	//↑控制猜数字的次数（步骤②）
		A=0;B=0;C=0;
		for(i=0;i<4;i++)
		scanf("%d",b+i);		//←用户输入猜测数存放再b[4]中。

		//↓找出AB两类数的个数（步骤③）
		for(i=0;i<4;i++){
			if (b[i]==a[i])A++;
			for(j=0;j<4;j++){
				C=b[i]==a[j]?++C:C;
				if (b[i]==a[j])break;
			}
		}
		B=C-A;// !!!

		//判断（步骤④）
		if(A==4){
			printf("恭喜你，猜对啦!\n");
			if (7-k>8-n){	//7-k相当于8-(k+1)表示未使用的机会次数，8-n表示最佳纪录时的未使用机会次数。
				n=k+1;
				printf("哇!刷新纪录!\a\n现在最佳纪录为%d次喽!\n",n);
			}
			else printf("猜对了，别骄傲哦，最佳纪录可是%d次呢!\n",n);
			printf("还玩吗？接着玩就按1，玩累了就按0休息一下吧 !\n");
			scanf("%d",&flag);
			if (flag){
                system("cls");
				printf("你想怎样获得随机数\n1.系统随机数\n2.自己输入\n");
				scanf("%d",&flag1);
				if(flag1==1){system("cls"); goto again1;}
				else{system("cls");goto again2;}
			}
			else break;
		}
		else printf("%dA%dB\n",A,B);
	}

	//步骤⑤
	if(A!=4){
		printf("OMG你输了!\n结果其实是:");
  		for (i=0;i<4;i++)
			printf("%d ",*(a+i));
        if(n==11)printf("\n小伙子加油，还没有最佳纪录,就等你了!\n");//初始值
		if(n!=11)printf("\n小伙子加油哦，最佳记录是:%d次。\n",n);
		printf("没事，人生不如意事十之八九!\n按1咱再玩一盘 ？或者按0休息一下再战吧!\n");
		scanf("%d",&flag);
		if (flag){
            system("cls");
            printf("你想怎样获得随机数\n1.系统随机数\n2.自己输入\n");
            scanf("%d",&flag1);
            if(flag1==1){system("cls"); goto again1;}
            else {system("cls"); goto again2;}
        }
	}
	goto menu;
	over:
	clan();
	getch();
	return 0;
}
