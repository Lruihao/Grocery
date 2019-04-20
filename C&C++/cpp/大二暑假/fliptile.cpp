#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int M,N;

int mapp[20][20];		  //�����������Ϣ
int temp[20][20];		  //����������õ���ʱ����

int status[20][20];		  //��ǰ�ķ�ת����
int ans[20][20];          //�洢��С��ת������Ӧ�ķ�ת����

int minflip;              //�洢��С�ķ�ת����

void flip(int i,int j){    //��תi,j��Ӧ�ķ�������������ҲҪ��ת
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

	int tot = 0;//��ת�Ĵ���

	for(int j = 1 ; j<=N ; j++){
		if(status[1][j]){
			flip(1,j);
			tot++;
		}
	}
	for(int i = 2 ; i<=M ; i++){
		for(int j = 1 ; j<=N ; j++){
			if(temp[i-1][j]){         //����ͷ�ϵ��Ǹ��Ǻ�ɫ������������ͷ���Ǹ���λ��ɰ�ɫ
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
		if(temp[M][i]==1){           //�ж����һ���ܷ�ȫ��Ϊ��ɫ�����к�ɫ�������������ȷ��return false
			return false;
		}
	}

	if(minflip > tot){               //���������У����жϴ�������С�����Ĺ�ϵ������ans
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
		bool flag = 0;                  //�Ƿ��п��еĲ���
		while (!status[1][N+1]){        //�˳�������status[1][N+1]==1.�����һ��1��nλ��������״̬��ö�ٹ���
			if(judge()){
				flag = 1;
			}

			status[1][1]++;                 //ģ�������ö������״̬
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
