#include <cstdio>
#define MAX(x,y) (x>y?x:y)
int DP[301][2],N[301];
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&N[i]);
		if(i==0){
			DP[0][0]=N[0];
			DP[0][1]=N[0];
		} else if(i==1){
			DP[i][0]=N[1];
			DP[i][1]=N[1]+N[0];
		} else {
			DP[i][0]=MAX(DP[i-2][0],DP[i-2][1])+N[i];
			DP[i][1]=DP[i-1][0]+N[i];
		}
	}
	printf("%ld",MAX(DP[t-1][0],DP[t-1][1]));
}