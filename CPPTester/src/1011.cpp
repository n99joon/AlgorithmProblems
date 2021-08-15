#include <cstdio>
#include <cmath>
int main() {
	int t,x,y,yO;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		x=y-x;
		y=ceil((sqrt(x+0.25)-0.5)*2);
		//printf("y = %d",y);
		yO=ceil((sqrt(x)-1)*2+1);
		//printf("yO = %d",yO);
		y=y<yO?y:yO;
		printf("%d\n",y);
	}
}