#include<bits/stdc++.h>
using namespace std;

int t[107];

int main()
{
	int n, a;
	while(cin>>n>>a){
		int sum = 0;
		for(int i =1; i <= n; i++)
			cin >> t[i];
		if(t[a]) sum++;//���ڳ������ﷸ
		for(int i = 1; i <= n; i++){
			if(a-i > 0&&a+i <= n) {
				if(t[a-i] == 1&&t[a+i] == 1)
					sum+=2;
			}
			else if(a-i <= 0&&a+i <= n){//�����ڵ�һ����
				if(t[a+i])
					sum++;
			}
			else if(a-i > 0&&a+i > n){
				if(t[a-i])
					sum++;
			}
		}
		cout <<sum<<endl;
	}
	return 0;
}
