#include<stdio.h>
int main(){
	int ah,bh,ch,am,bm,cm,as,bs,cs,n,i;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
			cs=(as+bs)%60;
			i=(as+bs)/60;
			cm=(am+bm+i)%60;
			i=(am+bm+i)/60;
			ch=ah+bh+i;
			printf("%d %d %d\n",ch,cm,cs);
		}
	}
	return 0;
}