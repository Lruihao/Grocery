#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
//������ϵͳ��ȡ������ĺ���
void get_x(int *p){
  int i, j;
  int x[4];
  srand(time(0));//�˺����ṩ���ӣ���time(0)ϵͳʱ������������rand()�����ṩ������ÿ�붼��һ��
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
      printf("%d ",x[i]);*/	//ע�Ͳ����ڲ���ʱ�����õ�������������ɵ�4λ�������
    for (i=0;i<4;i++)
      printf("* ");
  printf("\n\n");
}

//�������û����뺯��
void yhsr(int *q){
	lab:printf("����������4��������ͬ�����֣�\n");
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
      printf("%d ",y[i]);*/ //ע�Ͳ����ڲ���ʱ�����õ�������������ɵ�4λ�������
  printf("\n\n");
}

void help(){
	printf("����\n\n����Ϸ�����ɳ���������������û������ĸ�0��9֮������֣��Ҳ��ظ���\n");
	printf("����Ϸ��ͨ����Ϸ��ʾ����˴���ƥ����������������֡�\n");
	printf("A��ʾλ����ȷ��������ȷ��B��ʾ������ȷ��λ�ò���ȷ��\n���ߣ������\n\n");
}
void clan(){
	system("cls");
	printf("��лʹ�ñ�����\n");
}

int main(){
	int a[4],b[4],i,j,k,n=11,A,B,C,flag,flag1,star;

	//�����˵�
	menu:
    system("cls");
	printf("\t��������Ϸ\n1.�����������\n2.�û���������\n3.����\n4.�˳���Ϸ\n");
	printf("���������ѡ�񲢰��س�������\n");
	shuru:scanf("%d",&star);
    if(star==1){system("cls");again1:get_x(a);star=1;}
    if(star==2){system("cls");again2:yhsr(a);star=2;}
	if(star==3){
        system("cls");
		help();
		printf("����������������˵�\n");
		getch();
		if(1)goto menu;
	}
	if(star==4)goto over;
	if(star!=1&&star!=2&&star!=3&&star!=4){
		printf("����������������룡\n");
		goto shuru;
	}
	star=0;

	printf("���������֣��ո����!\n");
	for(k=0;k<8;k++){
	//�����Ʋ����ֵĴ���������ڣ�
		A=0;B=0;C=0;
		for(i=0;i<4;i++)
		scanf("%d",b+i);		//���û�����²��������b[4]�С�

		//���ҳ�AB�������ĸ���������ۣ�
		for(i=0;i<4;i++){
			if (b[i]==a[i])A++;
			for(j=0;j<4;j++){
				C=b[i]==a[j]?++C:C;
				if (b[i]==a[j])break;
			}
		}
		B=C-A;// !!!

		//�жϣ�����ܣ�
		if(A==4){
			printf("��ϲ�㣬�¶���!\n");
			if (7-k>8-n){	//7-k�൱��8-(k+1)��ʾδʹ�õĻ��������8-n��ʾ��Ѽ�¼ʱ��δʹ�û��������
				n=k+1;
				printf("��!ˢ�¼�¼!\a\n������Ѽ�¼Ϊ%d���!\n",n);
			}
			else printf("�¶��ˣ��𽾰�Ŷ����Ѽ�¼����%d����!\n",n);
			printf("�����𣿽�����Ͱ�1�������˾Ͱ�0��Ϣһ�°� !\n");
			scanf("%d",&flag);
			if (flag){
                system("cls");
				printf("����������������\n1.ϵͳ�����\n2.�Լ�����\n");
				scanf("%d",&flag1);
				if(flag1==1){system("cls"); goto again1;}
				else{system("cls");goto again2;}
			}
			else break;
		}
		else printf("%dA%dB\n",A,B);
	}

	//�����
	if(A!=4){
		printf("OMG������!\n�����ʵ��:");
  		for (i=0;i<4;i++)
			printf("%d ",*(a+i));
        if(n==11)printf("\nС���Ӽ��ͣ���û����Ѽ�¼,�͵�����!\n");//��ʼֵ
		if(n!=11)printf("\nС���Ӽ���Ŷ����Ѽ�¼��:%d�Ρ�\n",n);
		printf("û�£�������������ʮ֮�˾�!\n��1������һ�� �����߰�0��Ϣһ����ս��!\n");
		scanf("%d",&flag);
		if (flag){
            system("cls");
            printf("����������������\n1.ϵͳ�����\n2.�Լ�����\n");
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
