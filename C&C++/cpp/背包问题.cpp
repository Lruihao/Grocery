#include <stdio.h>
#include <windows.h>     //system("cls")��������
#define size 50

struct stacks {
	int data[size];
	int top;
} stack;


void bag(){
    int w[size];//���
	int V;
	int i = 0;
	int j = 0;
	int number;
	printf("\t**�򵥱�������**\n\n");
	printf("\n��������Ʒ�ĸ�����\n");
	scanf("%d", &number);
	printf("\n�����������Ʒ�������\n");
	for (i = 0; i < number; i++)
		scanf("%d", &w[i]);

	//����������������ѡ���������������ֵ���䣩
	for(i=0;i<number;i++)
		for(j=i+1;j<number;j++)
			if(w[i]>w[j]){
				w[i]=w[i]^w[j];
				w[j]=w[i]^w[j];
				w[i]=w[i]^w[j];
			}

	printf("\n�����뱳�����������\n");
	scanf("%d", &V);
	getchar();    //���ջس�
	while(V <= 0){
		printf("���뱳����������������룡\n");
		scanf("%d",&V);
		getchar();
	}

	//Ԥ����
	int s = 0;
	for (i = 0; i < number; i++)
		s = s + w[i];
	if(V > s){
		printf("�����޽⣡\n");
		printf("������������˵���\n");
        getchar(); //��ʱЧ����˳�����������
        system("cls");
		return;
	}
	if(V==s){
		printf("ֻ��һ�����������Ľ⣺");
		for (i = 0; i < number; i++)
            printf("%d ",w[i]);
        printf("\n");
        printf("������������˵���\n");
        getchar();
        system("cls");
		return;
	}

	//��ʼ��ջ
	for (i = 0; i < number; i++)
        stack.data[i] = 0;
	stack.top = 0;

    j=1;
    int k=0;
    int flag=0;
    do {
		while (V > 0 && k <= number) {
			if (V >= w[k]) {
				stack.data[stack.top] = k;//��k����Ʒ������±�
				stack.top++;
				V -= w[k];
			}
			k++;
		}

		if (V == 0) {
			flag=1;
			printf("��%d�����������Ľ⣺", j);
			for (i = 0; i < stack.top; i++) {
				printf("%d ", w[stack.data[i]]);
			}
			j++;
			printf("\n");
		}
		//k��ʱ����
		k = stack.data[--stack.top];
		stack.data[stack.top] = 0;
		V += w[k];
		k++;
	} while (!(stack.top == 0 && k == number));
	if(!flag){
		printf("�����޽⣡\n");
	}

	printf("������������˵���\n");
	getchar();
	system("cls");
}

void bag01(){

    int m[size][101] = {{0}},n,i,j,T;
    int w[size]={0};  //��ֵ
    int v[size]={0}; //�������
    printf("\t**01��������**\n\n");
    printf("��������Ʒ�ĸ�����\n");
    scanf("%d",&n);
    printf("�����������Ʒ�������\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("�����������Ʒ�ļ�ֵ��\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("�����뱳�����������\n");
    scanf("%d",&T);
    getchar();
    while(T <= 0){
		printf("���뱳����������������룡\n");
		scanf("%d",&T);
		getchar();
	}
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=T; j++)
        {                           //״̬���̣��ж��Ƿ�װ�룬
            if(j<v[i])
                m[i][j] = m[i-1][j];
            else
                m[i][j] = m[i-1][j]>(m[i-1][j-v[i]] + w[i])?m[i-1][j]:(m[i-1][j-v[i]] + w[i]);
            //printf("%d ",m[i][j]);  //��̬�滮���̴��
        }
        //printf("\n");
    }
    printf("�����ܴ��ߵ�����ֵΪ��\n");
    printf("%d\n",m[n][T]);

    printf("������������˵���\n");
	getchar();
	system("cls");
}

int main() {
    int i=0,f=0;//fΪ��Ŵ���ı�־
    while(i!=3){
    printf("\t**��������**\n\n");
    printf("\t-->1.�򵥱���\n");
    printf("\t-->2.01����\n");
    printf("\t-->3.�˳�\n\n");
    printf("������ţ�\n");
    while(!f){
    scanf("%d",&i);
    switch(i){
        case 1: system("cls");bag();f=1;break;
        case 2: system("cls");bag01();f=1;break;
        case 3: f=1;break;
        default: printf("��Ŵ��������䣡\n");f=0;break;
    }
    }
    f=0;
    }
	return 0;
}

