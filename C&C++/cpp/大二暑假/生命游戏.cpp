#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WIDE 70
#define HIGH 40
#define PERCENT 0.5
/*
 * WIDE ��̬����Ŀ�ȣ��м���
 * HIGH ��̬����ĸ߶�
 * PERCENT ��ıȣ�������������������������Ȼ���Լ�������������������죬��������С�ʣ��ı�������
 */
struct LIFE//���� �ṹ��
{
    int kind;//����  �ݣ�1 ��2 �ǣ�3
    int sex;//�Ա�  �ۣ�1 �ƣ�2
    int age;//����
    int food;//��ǰ��ʳ���������ڴ����������������
    int body;//��ǰ���屾�������
    int movement;//�Ƿ��Ѿ��ƶ�
    int bag;//Я����ʳ����
    int pregnant;//��������
};
struct RULE//������� �ṹ��
{
    int need;//���������ʳ��������
    int maxage;//�������
    int begin_age;//��ʼ��������
    int end_age;//��������
    int move;//����ƶ�����
    int body;//������������
    int plus;// ÿ�����������ӵ�����
    int bag;//������Я�������ʳ����
    int pregnant;//��������
    int child;//����������
};
struct WORLD//������� �ṹ��
{
    float born[5];//����ÿ�����ڵĳ�������
    int offer[5];//ÿ������ÿ�����Ȼ�ṩ������
    int appear[6];//��ʼ��ʱ��������ָ���
};
struct OBSERVE//ͳ������ �ṹ��
{
    int sex;//������
    int born;//������
    int hungry;//������
    int hungry_die;//��������
    int nature_die;//��Ȼ�����������ﵽ�������ޣ�
    int be_killed;//��ɱ��������
    int hard_born;//�Ѳ���������������ʱ�Ѿ����ڼ����У�����������
};
struct LIFE map[HIGH+2][WIDE+2],//��ͼ ��ÿ�����ӵ����ݣ�
			L[4],//��������ĳ�ʼ����ģ��
			temporary; //������ŵ�ǰ�������㴦����Ǹ�����
struct RULE R[4];//���ÿ���������Ľṹ������
struct WORLD god;//����������Ľṹ�����
struct OBSERVE O[4];//���ÿ������ͳ�����ݵĽṹ������
double energy,//����Ȼ�ṩ������
		energy1,//ɶ���⣿
	    energy_need,//�������������
		energy_max,//����Ȼ�ṩ��������ʷ���ֵ
		energy_min,//����Ȼ�ṩ��������ʷ��Сֵ
		energy_need_max,//һ��������������ʷ���ֵ
		energy_need_min;//һ��������������ʷ��Сֵ
int season,//��ǰ����
	date,//��
	year,//��
	month,//��
	move_x,//��ǰ����λ���ƶ�����ʱ����
	move_y,//��ǰ����λ���ƶ�����ʱ����
	year1,//Ŀ�����
	season1,//Ŀ�꼾��
	month1,//Ŀ���·�
	date1;//Ŀ������
long all[4],//�����������
	max[4],//�������������
	min[4];//��С�����������
char c,//����û�����ָ��ı���
	s[5][20]={" ","����","�ļ�","�＾","����"};//���ڵ�����

void clear();//�������ͳ������
void time_system();//�������ڵı仯
void eat_system(int i,int j);//��ʳϵͳ
void sex_system(int i,int j);//����ϵͳ����
void rand_born(int x);//�����ʼ��������ֲ���  x����������
void grow_system();//���������ʼ�����հ׵�����һ���ĸ��ʳ��ݣ�
void age_system();//������������ϵͳ
int move_system(int i,int j,int tx,int ty);//�����ƶ�ϵͳ
void pregnant_system(int i,int j);//���в���ϵͳ
void hungry_die_system();//����Ķ������� ����������������������ڴ���Ȼʵ��������ʱ�򣬰������ı������������һЩ�ݣ�
void god_see();//���ͳ������
void disaster_system(char c1);//����ϵͳ
void help_system();//�������
int date_judge(int y,int m,int d);//�ж�ÿ�����м���
void print_system();//�����ͼ ���������û��Ĳ�������
void daily();//ģ��һ��
void original();//ϵͳ��ʼ��


int main()
{
	int i,j;
	printf("~~~��ӭʹ��ģ����̬ϵͳV1.2~~~\n");
    printf("     ����: Amos Sang.\n\n\n");
    printf("˵����\n");
    printf("��ϵͳ��ģ������������������ܡ���ʳ��������\n");
    printf("ģ����̬ϵͳ�а�����������ݣ����ǣ�\n");
    printf("        �ݣ�  ��.��;\n        ���򣺡�%c��;    ĸ�򣺡�%c��;\n        ���ǣ���%c��;    ĸ�ǣ���%c��;\n\n\n",11,12,2,1);
    printf("ע�⣺��ѳ��򴰿ڵ�����󻯣��Ա�ﵽ���õ�ʹ��Ч����\n\n\n");
    printf("�밴������鿴����������\n");
    c=getch();
    for (i=1;i<=c;i++) j=rand()%100;
    system("cls");
    help_system();
    original();
    system("pause");
    return 0;
}

//�������ͳ������
void clear()
{
    int i;
    for (i=1;i<=3;i++)
    {
        O[i]=O[0];
    }
}

//�������ڵı仯
void time_system()
{
    if (((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))&&(date<31))
    {
        date++;
    }
    else if (((month==4)||(month==6)||(month==9)||(month==11))&&(date<30))
    {
    	date++;
    }
    else if ((month==2)&&(year%4==0)&&(year%100!=0)&&(date<29))
    {
    	date++;
    }
    else if ((month==2)&&((year%4!=0)||(year%100==0))&&(date<28))
    {
    	date++;
    }
    else
    {
        date=1;
        if(month<12)
        {
            month++;
            if (month%3==0)
            {
                if (season<4)
                {
                    season++;

                }
                else
                {
                	season=1;
                }
            }
        }
        else
        {
        	month=1;
        	year++;
        }
    }
	if ((year==0)&&(month==3)&&(date==1)) rand_born(2);
	if ((year==0)&&(month==6)&&(date==1)) rand_born(3);
}

//��ʳϵͳ
void eat_system(int i,int j)
{
    int i1,j1,k1,x,b,Rbag,Rneed,Rbody,Rplus,Rchild,find;//������ʱ����
    if (temporary.kind>1)//�Ǻ������Ҫ��ʳ
    {
    	Rbag=R[temporary.kind].bag;
    	Rneed=R[temporary.kind].need;
    	Rbody=R[temporary.kind].body;
    	Rchild=0;
    	find=1;
		if (temporary.pregnant>=0)//���е�������Ҫ���������Ǻ��ӵ�������
		{
			//�Լ�Ҳû����������㷨��Ŀ��������
			Rbag=Rbag+R[temporary.kind].child*3;
			Rneed=Rneed+R[temporary.kind].child;
			Rbody=Rbody+R[temporary.kind].child*2;
			Rchild=R[temporary.kind].child;
		}
        k1=temporary.kind-1;//����Ҫ��ʳ��Ŀ���������ͣ��ǳ�����Բݣ�
        for(i1=i-find;i1<=i+find;i1++)
        {
            for(j1=j-find;j1<=j+find;j1++)
            {
                if ((i1>=1)&&(i1<=HIGH)&&(j1>=1)&&(j1<=WIDE)&&(temporary.bag<Rbag))
                {
                    if ((map[i1][j1].kind==k1)&&(!((i1==i)&&(j1==j))))//�ҵ���ʳĿ��
                    {
                        x=map[i1][j1].body;
                        temporary.food=temporary.food+x;//ʳ��������˱���ʳ�ߵ���������
                        if (temporary.food>Rneed)//��ʳ�߳Բ���ʳ��
                        {
                            x=temporary.food-Rneed;
                            temporary.food=Rneed;
                            temporary.bag=temporary.bag+x;//��ʣ������ʴ��뱳����
                            if (temporary.bag>Rbag)//����������
                            {
                                energy=energy+(temporary.bag-Rbag)*PERCENT;//ʣ�µ���������������Ȼ�����������趨����ıȽ��з�����
								temporary.bag=Rbag;
                            }
                        }
                        O[map[i1][j1].kind].be_killed++;//�Ǹ����ﱻɱ����
                        all[map[i1][j1].kind]--;//��ɱ�����������������-1
                        map[i1][j1]=L[0];//����ͼ����Ϊ0
                    }
                }
            }
        }
        if (temporary.food<Rneed)//��ʳ��֮�����޷���������û�Ա���
        {
            b=temporary.food+temporary.bag;//���������Я����ʳ��
            if (b>=Rneed)//����Я����ʳ�ﹻ�ԣ��ǾͳԵ���Ӧ�Ĳ���
            {
                temporary.bag=b-Rneed;
                temporary.food=Rneed;
                if(temporary.body<Rbody)//���岻�������ĳɳ���Χ
		        {
		            temporary.body=temporary.body+R[temporary.kind].plus;//��������
		            if (temporary.pregnant>=0)//����ǻ���״̬
			        {
			            temporary.body=temporary.body+Rchild;//�������������˻��еĲ���
			        	energy_need=energy_need+Rchild;	//����Ȼ�������������˻��е���������Լ�Ҳû����
		         	}
			        if (temporary.body>Rbody) temporary.body=Rbody;
                }
            }
            else//����Я����ʳ��Ҳ������
            {
            	temporary.bag=0;
                temporary.food=b;
                temporary.body=temporary.body+temporary.food-Rneed;//�����ԵĲ��֣������Լ�����
                if (temporary.body<=0)//�����������Ϊ0������
                {
                	O[temporary.kind].hungry_die++;//����Ӧ���������������
                    all[temporary.kind]--;//��Ӧ�������������
                	temporary=L[0];//����ͼ����Ϊ��
                }
                else//û����
                {
                	O[temporary.kind].hungry++;//��Ӧ����ļ�����������
                }
            }
        }
		else if(temporary.body<Rbody)//ʳ���Ѿ����������ˣ�������岻�������ĳɳ���Χ
		{
		    temporary.body=temporary.body+R[temporary.kind].plus;//��������
		    if (temporary.pregnant>=0)//����ǻ���״̬
			{
			    temporary.body=temporary.body+Rchild;//�������������˻��еĲ���
				energy_need=energy_need+Rchild;	//����Ȼ���������������˻��е���������Լ�Ҳû����
			}
			if (temporary.body>Rbody) temporary.body=Rbody;
        }
    }
    else//������Ҫ����Ȼ�ṩ������
    {
        energy_need=energy_need+2;// ����Ȼ����������������2��2�������ò�����Լ������
        if (season<3)//����Ǵ�������������
        {
        	//�ݻ�ȡ������Ȼ������
            temporary.food=2;
            if (temporary.body<R[temporary.kind].body) temporary.body=temporary.body+temporary.food;
            if (temporary.body>R[temporary.kind].body) temporary.body=R[temporary.kind].body;
        }
        else//����������������٣�
        {
        	//�ݻ�ȡ������Ȼ������
            temporary.food=1;
            if (temporary.body<R[temporary.kind].body) temporary.body=temporary.body+temporary.food;
            if (temporary.body>R[temporary.kind].body) temporary.body=R[temporary.kind].body;
        }
    }
}

//����ϵͳ����
void sex_system(int i,int j)
{
    int i1,j1;
    for(i1=i-2;i1<=i+2;i1++)
    {
        for(j1=j-2;j1<=j+2;j1++)
        {
        	if((i1>=1)&&(i1<=HIGH)&&(j1>=1)&&(j1<=WIDE))
        	{
                if((map[i1][j1].kind==temporary.kind)&&(map[i1][j1].sex==1))//�ҵ��ɽ���Ķ���
                {
                    temporary.pregnant=0;//����������0��ʼ����
                    O[temporary.kind].sex++;//��Ӧ���ֵĽ���ͳ����������
                }
            }
        }
    }
}

//�����ʼ��������ֲ���  x����������
void rand_born(int x)
{
    int i,j,k;
    for (i=1;i<=HIGH;i++)
    {
        for (j=1;j<=WIDE;j++)
        {
            if(map[i][j].kind<=1)//����ط��ǿյĻ����ǲݵ�
            {
                k=rand()%1000;
                if (k<=god.appear[x])//��ʼ���ĳ��ָ���
                {
                	if (map[i][j].kind==1)// ����ط��ǲݡ������ͱ�������
                    {
                        O[map[i][j].kind].be_killed++;
                        energy=energy+map[i][j].body*PERCENT;
                        all[map[i][j].kind]--;
                    }
                    map[i][j]=L[x];
                    energy_need=energy_need+L[x].body;//
                    O[x].born++;
                    all[x]++;
                    map[i][j].sex=rand()%2+1;//�Ա�
                }
            }
        }
    }
}

//���������ʼ�����հ׵�����һ���ĸ��ʳ��ݣ�
void grow_system()
{
    int x;
    x=rand()%1000;
    if ((x>=0)&&(x<=god.born[season]))
    {
        temporary=L[1];
        energy_need=energy_need+L[1].body;
        O[1].born++;
        all[1]++;
    }
}

//������������ϵͳ
void age_system()
{
    if(temporary.age<R[temporary.kind].maxage)//��������������
    {
        temporary.age++;//����+1
        if (temporary.pregnant!=-1) temporary.pregnant++;//��������+1
    }
    else//�����ˡ�����
    {
        energy=energy+(temporary.body+temporary.bag)*PERCENT;
        O[temporary.kind].nature_die++;
        all[temporary.kind]--;
        temporary=L[0];
    }
}

//�����ƶ�ϵͳ
int move_system(int i,int j,int tx,int ty)
{
    int k;
    if (abs(move_x)+abs(move_y)==0)//�Լ�Ҳû����
    {
        if(i==1)
        {
            tx=1;
        }
        else if(i==HIGH)
        {
            tx=-1;
        }
        else
        {
            tx=rand()%2;
            if(tx==0) tx=-1;
        }
        if(j==1)
        {
            ty=1;
        }
        else if(j==WIDE)
        {
            ty=-1;
        }
        else
        {
            ty=rand()%2;
            if(ty==0) ty=-1;
        }
    }
    if ((abs(move_x)+abs(move_y))<R[temporary.kind].move)//����������ƶ�����
    {
        k=rand()%2;
        if ((k==0)&&((i+tx)>=1)&&((i+tx)<=HIGH))
        {
            if (map[i+tx][j].kind<=1)
            {
                i=i+tx;
                move_x=move_x+tx;
                move_system(i,j,tx,ty);
            }
        }
        if ((k==1)&&((j+ty)>=1)&&((j+ty)<=WIDE))
        {
            if (map[i][j+ty].kind<=1)
            {
                j=j+ty;
                move_y=move_y+ty;
                move_system(i,j,tx,ty);
            }
        }
    }
}

//���в���ϵͳ
void pregnant_system(int i,int j)
{
    int i1,j1,x,b;
    x=0;//�Ѳ��ӵ�����
    b=map[i][j].body+map[i][j].bag;
    for(i1=i-1;(i1<=i+1)&&(b>0);i1++)
    {
        for(j1=j-1;(j1<=j+1)&&(b>0);j1++)
        {
            if((x<R[map[i][j].kind].child)&&(map[i1][j1].kind<map[i][j].kind)&&(i1>=1)&&(i1<=HIGH)&&(j1>=1)&&(j1<=WIDE))
            {//�˵��ܲ���
                if (map[i1][j1].kind>0)//������ӵ����ܱ��Լ�ɱ�������֣���ô�͸ɵ���
                {
                    O[map[i1][j1].kind].be_killed++;
                    energy=energy+(map[i1][j1].body+map[i1][j1].bag)*PERCENT;
                    all[map[i1][j1].kind]--;
                }
				map[i1][j1]=L[map[i][j].kind];
				map[i1][j1].sex=rand()%2+1;
                O[map[i][j].kind].born++;
                all[map[i][j].kind]++;
                x++;
            }
            if (b>0) b=b-5;//��������5����������������������Լ�����⵱ʱ��˼·�ˣ�
            if (b<=0)//�������Ĺ��ˣ��Ѳ�������
            {
            	O[map[i][j].kind].hard_born++;
            	all[map[i][j].kind]--;
            	map[i][j]=L[0];
            }
        }
    }
    if (x<R[map[i][j].kind].child)//���������û�����㹻��������
    {
    	for (i1=x+1;(b>0)&&(i1<=R[map[i][j].kind].child);i1++)
    	{
    		//�����ۼ�����
    		b=b-5;
			if (b<=0)
			{
				energy=energy+(5+b)*PERCENT;
				O[map[i][j].kind].hard_born++;
				all[map[i][j].kind]--;
				map[i][j]=L[0];
			}
			else//��Щ������������û�ռ䣬������
			{
				energy=energy+5*PERCENT;
			}
    	}
    }
    if (b>0)//���꺢�ӣ����廹��ʣ��������Ҳ���ǻ�����
    {
    	map[i][j].body=b;
    	//��δ���еı�׼��������������������������
    	if (map[i][j].body>R[map[i][j].kind].body)
		{
	        b=map[i][j].body-R[map[i][j].kind].body;
			map[i][j].body=R[map[i][j].kind].body;
	        map[i][j].bag=b;
	        if (map[i][j].bag>R[map[i][j].kind].bag)
			 {
			     b=(map[i][j].bag-R[map[i][j].kind].bag)*PERCENT;
			     energy=energy+b*PERCENT;
				 map[i][j].bag=R[map[i][j].kind].bag;
			 }
	    }
    }
}

//����Ķ������� ����������������������ڴ���Ȼʵ��������ʱ�򣬰������ı������������һЩ�ݣ�
void hungry_die_system()
{
    int i,j,k;
    float x;
    x=energy_need-energy;
    x=(x/energy_need)*1000;
    if(x<1) x=1;
    for(i=1;i<=HIGH;i++)
    {
        for(j=1;j<=WIDE;j++)
        {
            if(map[i][j].kind==1)
            {
                k=rand()%1000;
                if(k<=x)
                {
                    O[1].hungry_die++;
                    energy1=energy1+map[i][j].body*PERCENT;
                    all[1]--;
                    map[i][j]=L[0];
                }
            }
        }
    }
}

//���ͳ������
void god_see()
{
    int i;
    system("cls");
    printf("����Ȼ�ṩ�������� %.2f\n",energy);
    printf("���������������   %.2f\n",energy_need);
     printf("--------------------\n");
    for (i=1;i<=3;i++)
    {
        if (i==1) printf("���ݡ��ĵ�������\n");
        if (i==2) printf("���򡯵ĵ�������\n");
        if (i==3) printf("���ǡ��ĵ�������\n");
        printf("��������� %d\n",all[i]);
        if (i!=1) printf("���������� %d\n",O[i].sex);
        printf("���������� %d\n",O[i].born);
        if (i!=1) printf("���������� %d\n",O[i].hungry);
        if (i!=1) printf("���������� %d\n",O[i].hungry_die);
        if (i!=1) printf("�Ѳ�����������   %d\n",O[i].hard_born);
        if (i==1) printf("��ή������ %d\n",O[i].hungry_die);
        printf("��Ȼ����������   %d\n",O[i].nature_die);
        printf("����Ȼ���������� %d\n",O[i].be_killed);
        printf("--------------------\n\n");
    }
    printf("����Ȼ�ṩ���������ֵ�� %.2f\n",energy_max);
    printf("����Ȼ�ṩ��������Сֵ�� %.2f\n",energy_min);
    printf("һ���������������ֵ�� %.2f\n",energy_need_max);
	printf("һ��������������Сֵ�� %.2f\n",energy_need_min);
    printf("--------------------\n\n");
    printf("���ݡ�������������� %d\n",max[1]);
    printf("���򡯵������������ %d\n",max[2]);
    printf("���ǡ�������������� %d\n",max[3]);
    printf("--------------------\n\n");
    printf("���ݡ�����С��������� %d\n",min[1]);
    printf("���򡯵���С��������� %d\n",min[2]);
    printf("���ǡ�����С��������� %d\n",min[3]);
    printf("--------------------\n");
}

//����ϵͳ
void disaster_system(char c1)
{
    int i,j,x,y;
    if (c1=='1')  //�����ʱ���в���
    {
        for (i=1;i<=HIGH;i++)
        {
            for (j=1;j<=WIDE;j++)
            {
                if (map[i][j].kind==1)
                {
                    all[1]--;
                    O[1].be_killed++;
                    energy=energy+map[i][j].body*PERCENT;
                    map[i][j]=L[0];
                }
            }
        }
    }
    else if (c1=='2') //�������50%
    {
        for (i=1;i<=HIGH;i++)
        {
            for (j=1;j<=WIDE;j++)
            {
                if (map[i][j].kind==2)
                {
                    x=rand()%100;
                    if (x<=50)
                    {
                        all[2]--;
                        O[2].be_killed++;
                        energy=energy+(map[i][j].body+map[i][j].bag)*PERCENT;
                        map[i][j]=L[0];
                    }
                }
            }
        }
    }
    else if (c1=='3') //�������50%
    {
        for (i=1;i<=HIGH;i++)
        {
            for (j=1;j<=WIDE;j++)
            {
                if (map[i][j].kind==3)
                {
                    x=rand()%100;
                    if (x<=50)
                    {
                        all[3]--;
                        O[3].be_killed++;
                        energy=energy+(map[i][j].body+map[i][j].bag)*PERCENT;
                        map[i][j]=L[0];
                    }
                }
            }
        }
    }
    else if (c1=='4') //�����������50%
    {
        for (i=1;i<=HIGH;i++)
        {
            for (j=1;j<=WIDE;j++)
            {
                if (map[i][j].kind>0)
                {
                    x=rand()%100;
                    if (x<=50)
                    {
                        all[map[i][j].kind]--;
                        O[map[i][j].kind].be_killed++;
                        energy=energy+(map[i][j].body+map[i][j].bag)*PERCENT;
                        map[i][j]=L[0];
                    }
                }
            }
        }
    }
    else if (c1=='5') //�����ͼ�����һ��10*20������
    {
        x=rand()%30;
        y=rand()%50;
        for (i=x+1;i<=x+10;i++)
        {
            for (j=y+1;j<=y+20;j++)
            {
                if (map[i][j].kind>0)
                {
                    all[map[i][j].kind]--;
                    O[map[i][j].kind].be_killed++;
                    energy=energy+(map[i][j].body+map[i][j].bag)*PERCENT;
                    map[i][j]=L[0];
                }
            }
        }
    }
}

//�������
void help_system()
{
    system("cls");
	printf("��ӭ�鿴����������\n\n");
    printf("���롮1�������ս����������в����������¼�\n");
    printf("���롮2�������ս�������һ�������������¼�\n");
    printf("���롮3�������ս�������һ�������������¼�\n");
    printf("���롮4�������ս�������һ�������������¼�\n");
    printf("���롮5�������ս�������20X10���������������������¼�\n");
    printf("���롮a�����鿴��������\n");
    printf("���롮m�����õ����Զ�ģ��1����\n");
    printf("���롮s�����õ����Զ�ģ��1������\n");
    printf("���롮y�����õ����Զ�ģ��1��\n");
    printf("���롮d�����õ����Զ�ģ��10��\n");
    printf("���롮f�����õ����Զ�ģ�⵽�û��趨��ʱ��\n");
    printf("���롮`������ʼ��ȫ�����ݣ����¿�ʼ��\n");
    printf("���롮q�����鿴��������\n");
    printf("�ڵ�ͼģʽ��������������������Խ��Զ�ģ��1��\n");
}

//�ж�ÿ�����м���
int date_judge(int y,int m,int d)
{
    if (((m==4)||(m==6)||(m==9)||(m==11))&&(d>30))   return 30;
    if ((m==2)&&(y%4==0)&&(y%100!=0)&&(d>29))   return 29;
    if ((m==2)&&((y%4!=0)||(y%100==0))&&(d>28)) return 28;
    if (d>31) d=31;
    return d;
}

//�����ͼ ���������û��Ĳ�������
void print_system()
{
    int i,j;
    char c1;
    printf(" ���ڣ� %4d �� - %2d �� - %2d �� < %s >\n",year,month,date,s[season]);
    for (i=1;i<=HIGH;i++)
    {
        for (j=1;j<=WIDE;j++)
        {
            if (map[i][j].kind==0) printf(" ");
            if (map[i][j].kind==1) printf(".");
            if (map[i][j].kind==2)
	    {
		if(map[i][j].sex==1) printf("%c",11);
                if(map[i][j].sex==2) printf("%c",12);
            }
            if (map[i][j].kind==3)
	    {
		if(map[i][j].sex==1) printf("%c",2);
                if(map[i][j].sex==2) printf("%c",1);
            }
        }
        printf("\n");
    }
    printf("�밴��Ӧ���������Ӧ���ܣ����롮q���鿴������������");
    c=getch();
    for (i=1;i<=c;i++) j=rand()%100;//��仰��ʲô��û������ò��ûɶ���塣
    if (c=='a') //��ʾ����ͳ��
    {
        god_see();
        printf("\n------------------\n");
        printf("�밴��������ص�ͼ\n");
        c1=getch();
        for (i=1;i<=c1;i++) j=rand()%100;//ʲô��Ϊɶ�ܳ��� ���ҵ�ʱ����ʲô
        system("cls");
        print_system();
    }
    else if (c=='q')//��ʾ����ϵͳ
    {
        help_system();
        printf("\n------------------\n");
        printf("�밴��������ص�ͼ\n");
        c1=getch();
        for (i=1;i<=c1;i++) j=rand()%100;//ʲô��Ϊɶ�ܳ��� ���ҵ�ʱ����ʲô
        system("cls");
        print_system();
    }
    else if (c=='y')//�õ����Զ�ģ��1��
    {
        year1=year+1; month1=month; season1=season; date1=date_judge(year1,month1,date);
    }
    else if (c=='m')// �õ����Զ�ģ��1����
    {
        if (month==12)
        {
            year1=year+1; month1=1; season1=season; date1=date;
        }
        else
        {
            year1=year; month1=month+1; season1=season;
            if (month1%3==0)
            {
                season1++;
                if (season1>4) season1=1;
            }
            date1=date_judge(year1,month1,date);
        }
    }
    else if (c=='s')//�õ����Զ�ģ��1������
    {
        month1=month+3; year1=year; date1=date;
        season1=season+1;
        if (season1>4) season1=1;
        if (month1>12)
        {
            month1=month1-12;
            year1++;
        }
        date1=date_judge(year1,month1,date);
    }
    else if (c=='d')//�õ����Զ�ģ��10��
    {
        year1=year+10; month1=month; season1=season; date1=date_judge(year1,month1,date);
    }
    else if (c=='f')//�Զ�ģ��ֱ��ָ������
    {
    	system("cls");
        printf("��������ݣ� "); scanf("%d",&year1);
        printf("�������·ݣ� "); scanf("%d",&month1);
        printf("���������ڣ� "); scanf("%d",&date1);
        if (month1>12) month1=12;
        if ((month1==12)||(month1==1)||(month1==2)) season1=4;
        if ((month1==3)||(month1==4)||(month1==5)) season1=1;
        if ((month1==6)||(month1==7)||(month1==8)) season1=2;
        if ((month1==9)||(month1==10)||(month1==11)) season1=3;
        date1=date_judge(year1,month1,date1);
        if ((year1<year)||((year1==year)&&(month1<month))||((year1==year)&&(month1==month)&&(date1<=date)))
        {
            printf("��������밴��������ص�ͼ��\n");
            c1=getch();
            for (i=1;i<=c1;i++) j=rand()%100;
            system("cls");
            print_system();
        }
    }
    else if (c=='`')//���¿�ʼ
    {
    	system("cls");
    	printf("���ٴ����롮`��ȷ�����¿�ʼ(���������������ģ����һ��)��");
        c=getch();
        for (i=1;i<=c;i++) j=rand()%100;
		system("cls");
		if (c=='`') original();
    }
}

//ģ��һ��
void daily()
{
    int i,j,k;
    system("cls");
    time_system();
    energy=energy*PERCENT+god.offer[season];
    energy_need=0;
    for (k=3;k>=0;k--)
    {
        for (i=1;i<=HIGH;i++)
        {
            for (j=1;j<=WIDE;j++)
            {
                if (map[i][j].kind==k)
                {
                    temporary=map[i][j];
                    //���в�ʳ
                    if (temporary.kind>0) eat_system(i,j);
                    //���н���
					if ((temporary.kind>1)&&(temporary.sex==2)&&(temporary.age>=R[temporary.kind].begin_age)&&(temporary.age<=R[temporary.kind].end_age)&&(temporary.pregnant==-1))
                    {
                        sex_system(i,j);
                    }
                    //�հ׵ĵ����Ƿ񳤳��µĲ�
                    if (temporary.kind==0) grow_system();
                    //��������
                    if (temporary.kind>0)  age_system();
                    map[i][j]=temporary;
                }
            }
        }
    }
    for (k=3;k>1;k--)
    {
        for (i=1;i<=HIGH;i++)
        {
            for (j=1;j<=WIDE;j++)
    	    {
    	    	//�����ƶ�
    	        if ((map[i][j].kind==k)&&(map[i][j].movement==0))
                {
    	    	    temporary=map[i][j];
    		        move_x=0; move_y=0;
                    move_system(i,j,0,0);//�����ƶ�
					//�ƶ�֮��ɱ���Ǹ������������
                    if ((map[i+move_x][j+move_y].kind>0)&&((abs(move_x)+abs(move_y))!=0))
                    {
                        O[map[i+move_x][j+move_y].kind].be_killed++;
                        energy=energy+map[i+move_x][j+move_y].body*PERCENT;
                        all[map[i+move_x][j+move_y].kind]--;
                    }
                    temporary.movement=1;
                    map[i+move_x][j+move_y]=temporary;
                    if ((abs(move_x)+abs(move_y))!=0) map[i][j]=L[0];
                }
            }
    	}
    }
    for (i=1;i<=HIGH;i++)
    {
        for (j=1;j<=WIDE;j++)
        {
            if ((map[i][j].kind>1)&&(map[i][j].pregnant>R[map[i][j].kind].pregnant))
            {
                pregnant_system(i,j);//��������
            }
        }
    }
    //�������ѣ��û�������
    if ((c>='1')&&(c<='5')) disaster_system(c);
    energy1=0;
    //����Ķ�������
    if (energy_need>energy) hungry_die_system();
    for (i=1;i<=HIGH;i++)
    {
        for (j=1;j<=WIDE;j++)
        {
            map[i][j].food=0;
            map[i][j].movement=0;
        }
    }
    if (year>0)//ϵͳ�տ�ʼʱǿ��ģ��һ�ꡣ֮��ſ�ʼ��¼����
    {
    	//��������ͳ��
    	for (i=1;i<=3;i++)
        {
            if (all[i]<min[i]) min[i]=all[i];
            if (all[i]>max[i]) max[i]=all[i];
        }
        if (energy_need>energy_need_max) energy_need_max=energy_need;
        if (energy_need<energy_need_min) energy_need_min=energy_need;
        if (energy>energy_max) energy_max=energy;
		if (energy<energy_min) energy_min=energy;
        if (((c=='m')||(c=='s')||(c=='y')||(c=='d')||(c=='f'))&&((year!=year1)||(season!=season1)||(month!=month1)||(date!=date1)))
        {
            printf("��ǰ���ڣ�%4d �� - %2d �� - %2d �� < %s >\n\n",year,month,date,s[season]);
            printf("Ŀ�����ڣ�%4d �� - %2d �� - %2d �� < %s >\n\n",year1,month1,date1,s[season1]);
            printf("ϵͳ���������У����Եȣ�\n");
        }
        else
        {
            print_system();
        }
    }
    else
    {
        printf("��ǰ���ڣ�  %4d �� - %2d �� - %2d �� < %s >\n\n",year,month,date,s[season]);
        printf("Ŀ�����ڣ�  %4d �� - %2d �� - %2d �� < %s >\n\n",1,1,1,s[4]);
        printf("����ģ����̬ϵͳ�ĳ�ʼ״̬�����Եȣ�\n");
    }
    energy=energy+energy1;
    clear();
    daily();
}

//ϵͳ��ʼ��
void original()
{
	//�������ݵĳ�ʼ��
    int i,j;
    i=0; L[i].kind=0; L[i].sex=0; L[i].age=0; L[i].food=0; L[i].body=0; L[i].bag=0; L[i].pregnant=-1; L[i].movement=0;
    O[0].sex=0; O[0].born=0; O[0].hungry=0; O[0].hungry_die=0; O[0].nature_die=0; O[0].be_killed=0;  O[0].hard_born=0;
    for (i=1;i<=3;i++)
    {
    	max[i]=-1;
    	min[i]=2801;
    }
    energy_need_max=0;
    energy_max=0;
    energy_need_min=10000;
    energy_min=10000;
    clear();
    R[1].need=2;  R[1].maxage=10;  R[1].begin_age=0;   R[1].end_age=0;   R[1].move=0;  R[1].bag=0;  R[1].pregnant=-1;  R[1].child=0;
    R[2].need=4;  R[2].maxage=20;  R[2].begin_age=4;   R[2].end_age=16;  R[2].move=7;  R[2].pregnant=2;  R[2].child=6; R[2].plus=3;
    R[3].need=9;  R[3].maxage=90;  R[3].begin_age=20;  R[3].end_age=70;  R[3].move=14; R[3].pregnant=15; R[3].child=2; R[3].plus=5;
    for (i=1;i<=3;i++)
    {
        L[i].kind=i; L[i].sex=0; L[i].age=0; L[i].food=0; L[i].bag=0; L[i].pregnant=-1; L[i].movement=0;
    }
    L[1].body=10;  L[2].body=12; L[3].body=15;
    R[1].body=15; R[2].body=20; R[3].body=30;  R[2].bag=R[1].body;   R[3].bag=R[2].body;
	for (i=0;i<=HIGH+1;i++)
    {
        for (j=0;j<=WIDE+1;j++)
        {
           map[i][j]=L[0];
        }
    }
    for (i=0;i<=3;i++) all[i]=0;
    god.born[1]=400;  god.born[2]=360;   god.born[3]=330;   god.born[4]=300;
    god.offer[1]=2100; god.offer[2]=2500; god.offer[3]=1700; god.offer[4]=1300;
    god.appear[2]=40; god.appear[3]=15;
    energy=3000;
    year=0;
    season=4;
    month=1;
    date=0;
    c=-1;
    printf("\n------------------\n");
    printf("�밴�������ʼ��Ϸ\n");
    c=getch();
    for (i=1;i<=c;i++) j=rand()%100;
    daily();
}
