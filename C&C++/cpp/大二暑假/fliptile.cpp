#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int M,N;

int mapp[20][20];		  //输入的网格信息
int temp[20][20];		  //处理操作所用的临时矩阵

int status[20][20];		  //当前的反转操作
int ans[20][20];          //存储最小反转次数对应的反转操作

int minflip;              //存储最小的反转次数

void flip(int i,int j){    //反转i,j对应的方格。其上下左右也要反转
	temp[i][j] = !temp[i][j];
	temp[i-1][j] = !temp[i-1][j];
	temp[i+1][j] = !temp[i+1][j];
	temp[i][j-1] = !temp[i][j-1];
	temp[i][j+1] = !temp[i][j+1];
}

bool judge(){
	for(int i = 1 ; i<=M ; i++){
		for(int j = 1 ; j<=N ; j++){
			temp[i][j] = mapp[i][j];
		}
	}

	int tot = 0;//反转的次数

	for(int j = 1 ; j<=N ; j++){
		if(status[1][j]){
			flip(1,j);
			tot++;
		}
	}
	for(int i = 2 ; i<=M ; i++){
		for(int j = 1 ; j<=N ; j++){
			if(temp[i-1][j]){         //若它头上的那个是黑色，则用它把它头上那个单位变成白色
				flip(i,j);
				tot++;
				status[i][j] = 1;
			}
			else{
				status[i][j] = 0;
			}
		}
	}

	for(int i = 1 ; i<=N ; i++){
		if(temp[M][i]==1){           //判断最后一行能否全部为白色，若有黑色则这个方法不正确，return false
			return false;
		}
	}

	if(minflip > tot){               //若方法可行，则判断次数与最小次数的关系，更新ans
		minflip = tot;
		for(int i = 1 ; i<=M ; i++){
			for(int j =1 ; j<=N ; j++){
				ans[i][j] = status[i][j];
			}
		}
	}
	return true;
}

int main(){
	while(scanf("%d %d",&M , &N)!=EOF){
		for(int i = 1 ; i<=M ; i++){
			for(int j = 1 ; j<=N ; j++){
				scanf("%d",&mapp[i][j]);
			}
		}

		memset(status,0,sizeof(status));

		minflip = 1<<30;
		bool flag = 0;                  //是否有可行的操作
		while (!status[1][N+1]){        //退出条件：status[1][N+1]==1.代表第一行1到n位置上所有状态都枚举过了
			if(judge()){
				flag = 1;
			}

			status[1][1]++;                 //模拟二进制枚举所有状态
			int c = 1;
			while (status[1][c]>1) {
				status[1][c] = 0;
				status[1][++c]++;
			}
		}

		if(!flag){
			printf("IMPOSSIBLE\n");
		}
		else{
			for(int i = 1 ; i<=M ; i++){
				for(int j = 1 ; j<=N ; j++){
					if(j==1)
						printf("%d",ans[i][j]);
					else{
						printf(" %d",ans[i][j]);
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
