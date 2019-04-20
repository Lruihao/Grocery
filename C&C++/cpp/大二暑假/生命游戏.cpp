#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WIDE 70
#define HIGH 40
#define PERCENT 0.5
/*
 * WIDE 生态区域的宽度（有几格）
 * HIGH 生态区域的高度
 * PERCENT 损耗比（躯体死亡后，能量返还给大自然，以及昨天的能量存留到今天，这个过程中“剩余的比例”）
 */
struct LIFE//生物 结构体
{
    int kind;//种类  草：1 羊：2 狼：3
    int sex;//性别  雄：1 雌：2
    int age;//年龄
    int food;//当前的食物量（体内储存待消化的能量）
    int body;//当前身体本身的能量
    int movement;//是否已经移动
    int bag;//携带的食物量
    int pregnant;//怀孕天数
};
struct RULE//生物规则 结构体
{
    int need;//生物生存的食物需求量
    int maxage;//最大寿命
    int begin_age;//起始生育年龄
    int end_age;//绝育年龄
    int move;//最大移动步数
    int body;//身体的最大能量
    int plus;// 每天身体能增加的能量
    int bag;//能随身携带的最大食物量
    int pregnant;//怀孕天数
    int child;//最大产子数量
};
struct WORLD//世界规则 结构体
{
    float born[5];//草类每个季节的出生概率
    int offer[5];//每个季节每天大自然提供的能量
    int appear[6];//初始化时的随机出现概率
};
struct OBSERVE//统计数据 结构体
{
    int sex;//交配数
    int born;//出生数
    int hungry;//饥饿数
    int hungry_die;//饿死数量
    int nature_die;//自然死亡数量（达到寿命上限）
    int be_killed;//被杀死的数量
    int hard_born;//难产死亡数量（产子时已经处于饥饿中，能量不够）
};
struct LIFE map[HIGH+2][WIDE+2],//地图 （每个格子的数据）
			L[4],//四种生物的初始数据模板
			temporary; //用来存放当前进行运算处理的那个生物
struct RULE R[4];//存放每个生物规则的结构体数组
struct WORLD god;//存放世界规则的结构体变量
struct OBSERVE O[4];//存放每个生物统计数据的结构体数组
double energy,//大自然提供的能量
		energy1,//啥玩意？
	    energy_need,//当日所需的能量
		energy_max,//大自然提供能量的历史最大值
		energy_min,//大自然提供能量的历史最小值
		energy_need_max,//一日所需能量的历史最大值
		energy_need_min;//一日所需能量的历史最小值
int season,//当前季节
	date,//日
	year,//年
	month,//月
	move_x,//当前生物位置移动的临时数据
	move_y,//当前生物位置移动的临时数据
	year1,//目标年份
	season1,//目标季节
	month1,//目标月份
	date1;//目标日期
long all[4],//存活数量数组
	max[4],//最大存活数量数组
	min[4];//最小存活数量数组
char c,//存放用户控制指令的变量
	s[5][20]={" ","春季","夏季","秋季","冬季"};//季节的中文

void clear();//清除所有统计数据
void time_system();//处理日期的变化
void eat_system(int i,int j);//捕食系统
void sex_system(int i,int j);//交配系统……
void rand_born(int x);//生物初始化（随机分布）  x：生物类型
void grow_system();//草类随机初始化（空白地区有一定的概率长草）
void age_system();//生物年龄增长系统
int move_system(int i,int j,int tx,int ty);//生物移动系统
void pregnant_system(int i,int j);//怀孕产子系统
void hungry_die_system();//草类的饿死机制 （当天的能量需求总量大于大自然实际能量的时候，按超出的比例，随机饿死一些草）
void god_see();//输出统计数据
void disaster_system(char c1);//灾难系统
void help_system();//输出帮助
int date_judge(int y,int m,int d);//判断每个月有几天
void print_system();//输出地图 ，并接收用户的操作控制
void daily();//模拟一天
void original();//系统初始化


int main()
{
	int i,j;
	printf("~~~欢迎使用模拟生态系统V1.2~~~\n");
    printf("     作者: Amos Sang.\n\n\n");
    printf("说明：\n");
    printf("本系统简单模拟了生物的生长、繁衍、捕食和死亡；\n");
    printf("模拟生态系统中包含三种生物：草，羊，狼；\n");
    printf("        草：  ‘.’;\n        公羊：‘%c’;    母羊：‘%c’;\n        公狼：‘%c’;    母狼：‘%c’;\n\n\n",11,12,2,1);
    printf("注意：请把程序窗口调至最大化，以便达到更好的使用效果！\n\n\n");
    printf("请按任意键查看按键帮助：\n");
    c=getch();
    for (i=1;i<=c;i++) j=rand()%100;
    system("cls");
    help_system();
    original();
    system("pause");
    return 0;
}

//清除所有统计数据
void clear()
{
    int i;
    for (i=1;i<=3;i++)
    {
        O[i]=O[0];
    }
}

//处理日期的变化
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

//捕食系统
void eat_system(int i,int j)
{
    int i1,j1,k1,x,b,Rbag,Rneed,Rbody,Rplus,Rchild,find;//各种临时变量
    if (temporary.kind>1)//狼和羊才需要捕食
    {
    	Rbag=R[temporary.kind].bag;
    	Rneed=R[temporary.kind].need;
    	Rbody=R[temporary.kind].body;
    	Rchild=0;
    	find=1;
		if (temporary.pregnant>=0)//怀孕的生物需要附带上他们孩子的需求量
		{
			//自己也没看懂这里的算法，目测有问题
			Rbag=Rbag+R[temporary.kind].child*3;
			Rneed=Rneed+R[temporary.kind].child;
			Rbody=Rbody+R[temporary.kind].child*2;
			Rchild=R[temporary.kind].child;
		}
        k1=temporary.kind-1;//找它要捕食的目标生物类型（狼吃羊，羊吃草）
        for(i1=i-find;i1<=i+find;i1++)
        {
            for(j1=j-find;j1<=j+find;j1++)
            {
                if ((i1>=1)&&(i1<=HIGH)&&(j1>=1)&&(j1<=WIDE)&&(temporary.bag<Rbag))
                {
                    if ((map[i1][j1].kind==k1)&&(!((i1==i)&&(j1==j))))//找到捕食目标
                    {
                        x=map[i1][j1].body;
                        temporary.food=temporary.food+x;//食物里加上了被捕食者的躯体能量
                        if (temporary.food>Rneed)//捕食者吃不完食物
                        {
                            x=temporary.food-Rneed;
                            temporary.food=Rneed;
                            temporary.bag=temporary.bag+x;//将剩余的物质存入背包里
                            if (temporary.bag>Rbag)//背包放满了
                            {
                                energy=energy+(temporary.bag-Rbag)*PERCENT;//剩下的能量返还给大自然总能量（按设定的损耗比进行返还）
								temporary.bag=Rbag;
                            }
                        }
                        O[map[i1][j1].kind].be_killed++;//那个生物被杀死了
                        all[map[i1][j1].kind]--;//被杀死的那类生物的数量-1
                        map[i1][j1]=L[0];//这块地图重置为0
                    }
                }
            }
        }
        if (temporary.food<Rneed)//捕食完之后发现无法满足需求（没吃饱）
        {
            b=temporary.food+temporary.bag;//打算吃随身携带的食物
            if (b>=Rneed)//随身携带的食物够吃，那就吃掉相应的部分
            {
                temporary.bag=b-Rneed;
                temporary.food=Rneed;
                if(temporary.body<Rbody)//身体不超过最大的成长范围
		        {
		            temporary.body=temporary.body+R[temporary.kind].plus;//身体生长
		            if (temporary.pregnant>=0)//如果是怀孕状态
			        {
			            temporary.body=temporary.body+Rchild;//身体能量增加了怀孕的部分
			        	energy_need=energy_need+Rchild;	//大自然的需求量增加了怀孕的量？这块自己也没看懂
		         	}
			        if (temporary.body>Rbody) temporary.body=Rbody;
                }
            }
            else//随身携带的食物也不够吃
            {
            	temporary.bag=0;
                temporary.food=b;
                temporary.body=temporary.body+temporary.food-Rneed;//不够吃的部分，消化自己……
                if (temporary.body<=0)//如果身体能量为0，死啦
                {
                	O[temporary.kind].hungry_die++;//死对应生物的亡数量增加
                    all[temporary.kind]--;//对应生物的数量减少
                	temporary=L[0];//这块地图重置为空
                }
                else//没饿死
                {
                	O[temporary.kind].hungry++;//对应生物的饥饿数量增加
                }
            }
        }
		else if(temporary.body<Rbody)//食物已经满足需求了，如果身体不超过最大的成长范围
		{
		    temporary.body=temporary.body+R[temporary.kind].plus;//身体生长
		    if (temporary.pregnant>=0)//如果是怀孕状态
			{
			    temporary.body=temporary.body+Rchild;//身体能量增加了怀孕的部分
				energy_need=energy_need+Rchild;	//大自然的能量需求增加了怀孕的量？这块自己也没看懂
			}
			if (temporary.body>Rbody) temporary.body=Rbody;
        }
    }
    else//草是需要大自然提供能量的
    {
        energy_need=energy_need+2;// 大自然的能量需求增加了2？2这个数字貌似是自己定义的
        if (season<3)//如果是春夏秋三个季节
        {
        	//草获取能量，然后生长
            temporary.food=2;
            if (temporary.body<R[temporary.kind].body) temporary.body=temporary.body+temporary.food;
            if (temporary.body>R[temporary.kind].body) temporary.body=R[temporary.kind].body;
        }
        else//冬季（能量需求更少）
        {
        	//草获取能量，然后生长
            temporary.food=1;
            if (temporary.body<R[temporary.kind].body) temporary.body=temporary.body+temporary.food;
            if (temporary.body>R[temporary.kind].body) temporary.body=R[temporary.kind].body;
        }
    }
}

//交配系统……
void sex_system(int i,int j)
{
    int i1,j1;
    for(i1=i-2;i1<=i+2;i1++)
    {
        for(j1=j-2;j1<=j+2;j1++)
        {
        	if((i1>=1)&&(i1<=HIGH)&&(j1>=1)&&(j1<=WIDE))
        	{
                if((map[i1][j1].kind==temporary.kind)&&(map[i1][j1].sex==1))//找到可交配的对象
                {
                    temporary.pregnant=0;//怀孕天数从0开始计算
                    O[temporary.kind].sex++;//对应物种的交配统计数据增加
                }
            }
        }
    }
}

//生物初始化（随机分布）  x：生物类型
void rand_born(int x)
{
    int i,j,k;
    for (i=1;i<=HIGH;i++)
    {
        for (j=1;j<=WIDE;j++)
        {
            if(map[i][j].kind<=1)//这个地方是空的或者是草地
            {
                k=rand()%1000;
                if (k<=god.appear[x])//初始化的出现概率
                {
                	if (map[i][j].kind==1)// 这个地方是草。。。就被踩死了
                    {
                        O[map[i][j].kind].be_killed++;
                        energy=energy+map[i][j].body*PERCENT;
                        all[map[i][j].kind]--;
                    }
                    map[i][j]=L[x];
                    energy_need=energy_need+L[x].body;//
                    O[x].born++;
                    all[x]++;
                    map[i][j].sex=rand()%2+1;//性别
                }
            }
        }
    }
}

//草类随机初始化（空白地区有一定的概率长草）
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

//生物年龄增长系统
void age_system()
{
    if(temporary.age<R[temporary.kind].maxage)//不超过年龄上限
    {
        temporary.age++;//年龄+1
        if (temporary.pregnant!=-1) temporary.pregnant++;//怀孕天数+1
    }
    else//老死了。。。
    {
        energy=energy+(temporary.body+temporary.bag)*PERCENT;
        O[temporary.kind].nature_die++;
        all[temporary.kind]--;
        temporary=L[0];
    }
}

//生物移动系统
int move_system(int i,int j,int tx,int ty)
{
    int k;
    if (abs(move_x)+abs(move_y)==0)//自己也没看懂
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
    if ((abs(move_x)+abs(move_y))<R[temporary.kind].move)//不超过最大移动步数
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

//怀孕产子系统
void pregnant_system(int i,int j)
{
    int i1,j1,x,b;
    x=0;//已产子的数量
    b=map[i][j].body+map[i][j].bag;
    for(i1=i-1;(i1<=i+1)&&(b>0);i1++)
    {
        for(j1=j-1;(j1<=j+1)&&(b>0);j1++)
        {
            if((x<R[map[i][j].kind].child)&&(map[i1][j1].kind<map[i][j].kind)&&(i1>=1)&&(i1<=HIGH)&&(j1>=1)&&(j1<=WIDE))
            {//此地能产子
                if (map[i1][j1].kind>0)//如果产子地是能被自己杀死的物种，那么就干掉它
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
            if (b>0) b=b-5;//产子消耗5身体能量（含背包能量额？自己不理解当时的思路了）
            if (b<=0)//能量消耗光了，难产，死了
            {
            	O[map[i][j].kind].hard_born++;
            	all[map[i][j].kind]--;
            	map[i][j]=L[0];
            }
        }
    }
    if (x<R[map[i][j].kind].child)//如果生孩子没生到足够的数量？
    {
    	for (i1=x+1;(b>0)&&(i1<=R[map[i][j].kind].child);i1++)
    	{
    		//继续扣减能量
    		b=b-5;
			if (b<=0)
			{
				energy=energy+(5+b)*PERCENT;
				O[map[i][j].kind].hard_born++;
				all[map[i][j].kind]--;
				map[i][j]=L[0];
			}
			else//这些孩子生下来就没空间，死掉了
			{
				energy=energy+5*PERCENT;
			}
    	}
    }
    if (b>0)//生完孩子，躯体还有剩余能量，也就是还活着
    {
    	map[i][j].body=b;
    	//按未怀孕的标准分配能量，避免能量超出上限
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

//草类的饿死机制 （当天的能量需求总量大于大自然实际能量的时候，按超出的比例，随机饿死一些草）
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

//输出统计数据
void god_see()
{
    int i;
    system("cls");
    printf("大自然提供的能量： %.2f\n",energy);
    printf("当日所需的能量：   %.2f\n",energy_need);
     printf("--------------------\n");
    for (i=1;i<=3;i++)
    {
        if (i==1) printf("‘草’的当日数据\n");
        if (i==2) printf("‘羊’的当日数据\n");
        if (i==3) printf("‘狼’的当日数据\n");
        printf("存活数量： %d\n",all[i]);
        if (i!=1) printf("受孕数量： %d\n",O[i].sex);
        printf("出生数量： %d\n",O[i].born);
        if (i!=1) printf("饥饿数量： %d\n",O[i].hungry);
        if (i!=1) printf("饿死数量： %d\n",O[i].hungry_die);
        if (i!=1) printf("难产死亡数量：   %d\n",O[i].hard_born);
        if (i==1) printf("枯萎数量： %d\n",O[i].hungry_die);
        printf("自然死亡数量：   %d\n",O[i].nature_die);
        printf("非自然死亡数量： %d\n",O[i].be_killed);
        printf("--------------------\n\n");
    }
    printf("大自然提供能量的最大值： %.2f\n",energy_max);
    printf("大自然提供能量的最小值： %.2f\n",energy_min);
    printf("一日所需能量的最大值： %.2f\n",energy_need_max);
	printf("一日所需能量的最小值： %.2f\n",energy_need_min);
    printf("--------------------\n\n");
    printf("‘草’的最大存活数量： %d\n",max[1]);
    printf("‘羊’的最大存活数量： %d\n",max[2]);
    printf("‘狼’的最大存活数量： %d\n",max[3]);
    printf("--------------------\n\n");
    printf("‘草’的最小存活数量： %d\n",min[1]);
    printf("‘羊’的最小存活数量： %d\n",min[2]);
    printf("‘狼’的最小存活数量： %d\n",min[3]);
    printf("--------------------\n");
}

//灾难系统
void disaster_system(char c1)
{
    int i,j,x,y;
    if (c1=='1')  //清除此时所有草类
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
    else if (c1=='2') //羊类灭绝50%
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
    else if (c1=='3') //狼类灭绝50%
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
    else if (c1=='4') //所有生物灭绝50%
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
    else if (c1=='5') //清除地图上随机一块10*20的土地
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

//输出帮助
void help_system()
{
    system("cls");
	printf("欢迎查看按键帮助！\n\n");
    printf("输入‘1’：次日将发生“所有草类死亡”事件\n");
    printf("输入‘2’：次日将发生“一半羊类死亡”事件\n");
    printf("输入‘3’：次日将发生“一半狼类死亡”事件\n");
    printf("输入‘4’：次日将发生“一半生物死亡”事件\n");
    printf("输入‘5’：次日将发生“20X10区域内所有生物死亡”事件\n");
    printf("输入‘a’：查看当日数据\n");
    printf("输入‘m’：让电脑自动模拟1个月\n");
    printf("输入‘s’：让电脑自动模拟1个季节\n");
    printf("输入‘y’：让电脑自动模拟1年\n");
    printf("输入‘d’：让电脑自动模拟10年\n");
    printf("输入‘f’：让电脑自动模拟到用户设定的时间\n");
    printf("输入‘`’：初始化全部数据（重新开始）\n");
    printf("输入‘q’：查看按键帮助\n");
    printf("在地图模式下输入其它任意键，电脑将自动模拟1天\n");
}

//判断每个月有几天
int date_judge(int y,int m,int d)
{
    if (((m==4)||(m==6)||(m==9)||(m==11))&&(d>30))   return 30;
    if ((m==2)&&(y%4==0)&&(y%100!=0)&&(d>29))   return 29;
    if ((m==2)&&((y%4!=0)||(y%100==0))&&(d>28)) return 28;
    if (d>31) d=31;
    return d;
}

//输出地图 ，并接收用户的操作控制
void print_system()
{
    int i,j;
    char c1;
    printf(" 日期： %4d 年 - %2d 月 - %2d 日 < %s >\n",year,month,date,s[season]);
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
    printf("请按相应按键进入对应功能（输入‘q’查看按键帮助）：");
    c=getch();
    for (i=1;i<=c;i++) j=rand()%100;//这句话是什么鬼，没看懂，貌似没啥意义。
    if (c=='a') //显示数据统计
    {
        god_see();
        printf("\n------------------\n");
        printf("请按任意键返回地图\n");
        c1=getch();
        for (i=1;i<=c1;i++) j=rand()%100;//什么鬼，为啥总出现 ，我当时在想什么
        system("cls");
        print_system();
    }
    else if (c=='q')//显示帮助系统
    {
        help_system();
        printf("\n------------------\n");
        printf("请按任意键返回地图\n");
        c1=getch();
        for (i=1;i<=c1;i++) j=rand()%100;//什么鬼，为啥总出现 ，我当时在想什么
        system("cls");
        print_system();
    }
    else if (c=='y')//让电脑自动模拟1年
    {
        year1=year+1; month1=month; season1=season; date1=date_judge(year1,month1,date);
    }
    else if (c=='m')// 让电脑自动模拟1个月
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
    else if (c=='s')//让电脑自动模拟1个季节
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
    else if (c=='d')//让电脑自动模拟10年
    {
        year1=year+10; month1=month; season1=season; date1=date_judge(year1,month1,date);
    }
    else if (c=='f')//自动模拟直到指定天数
    {
    	system("cls");
        printf("请输入年份： "); scanf("%d",&year1);
        printf("请输入月份： "); scanf("%d",&month1);
        printf("请输入日期： "); scanf("%d",&date1);
        if (month1>12) month1=12;
        if ((month1==12)||(month1==1)||(month1==2)) season1=4;
        if ((month1==3)||(month1==4)||(month1==5)) season1=1;
        if ((month1==6)||(month1==7)||(month1==8)) season1=2;
        if ((month1==9)||(month1==10)||(month1==11)) season1=3;
        date1=date_judge(year1,month1,date1);
        if ((year1<year)||((year1==year)&&(month1<month))||((year1==year)&&(month1==month)&&(date1<=date)))
        {
            printf("输入错误！请按任意键返回地图！\n");
            c1=getch();
            for (i=1;i<=c1;i++) j=rand()%100;
            system("cls");
            print_system();
        }
    }
    else if (c=='`')//重新开始
    {
    	system("cls");
    	printf("请再次输入‘`’确认重新开始(按其余任意键继续模拟下一天)！");
        c=getch();
        for (i=1;i<=c;i++) j=rand()%100;
		system("cls");
		if (c=='`') original();
    }
}

//模拟一天
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
                    //进行捕食
                    if (temporary.kind>0) eat_system(i,j);
                    //进行交配
					if ((temporary.kind>1)&&(temporary.sex==2)&&(temporary.age>=R[temporary.kind].begin_age)&&(temporary.age<=R[temporary.kind].end_age)&&(temporary.pregnant==-1))
                    {
                        sex_system(i,j);
                    }
                    //空白的地区是否长出新的草
                    if (temporary.kind==0) grow_system();
                    //年龄增长
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
    	    	//进行移动
    	        if ((map[i][j].kind==k)&&(map[i][j].movement==0))
                {
    	    	    temporary=map[i][j];
    		        move_x=0; move_y=0;
                    move_system(i,j,0,0);//进行移动
					//移动之后杀死那个格子里的生物
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
                pregnant_system(i,j);//怀孕生产
            }
        }
    }
    //制造灾难（用户操作）
    if ((c>='1')&&(c<='5')) disaster_system(c);
    energy1=0;
    //草类的饿死机制
    if (energy_need>energy) hungry_die_system();
    for (i=1;i<=HIGH;i++)
    {
        for (j=1;j<=WIDE;j++)
        {
            map[i][j].food=0;
            map[i][j].movement=0;
        }
    }
    if (year>0)//系统刚开始时强制模拟一年。之后才开始记录数据
    {
    	//进行数据统计
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
            printf("当前日期：%4d 年 - %2d 月 - %2d 日 < %s >\n\n",year,month,date,s[season]);
            printf("目标日期：%4d 年 - %2d 月 - %2d 日 < %s >\n\n",year1,month1,date1,s[season1]);
            printf("系统正在运算中，请稍等！\n");
        }
        else
        {
            print_system();
        }
    }
    else
    {
        printf("当前日期：  %4d 年 - %2d 月 - %2d 日 < %s >\n\n",year,month,date,s[season]);
        printf("目标日期：  %4d 年 - %2d 月 - %2d 日 < %s >\n\n",1,1,1,s[4]);
        printf("正在模拟生态系统的初始状态，请稍等！\n");
    }
    energy=energy+energy1;
    clear();
    daily();
}

//系统初始化
void original()
{
	//各种数据的初始化
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
    printf("请按任意键开始游戏\n");
    c=getch();
    for (i=1;i<=c;i++) j=rand()%100;
    daily();
}
