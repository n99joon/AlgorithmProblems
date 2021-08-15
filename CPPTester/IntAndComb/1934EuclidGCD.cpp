#include <cstdio>

int GCD(int x, int y){
	if(x%y==0)return y;
	else return GCD(y,x%y);
}

int main(){
	int t,x,y,G;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(x>y)G=GCD(x,y);
		else G=GCD(y,x);
		printf("%d\n",x*y/G);
	}
}