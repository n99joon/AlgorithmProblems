#include <cstdio>
#define MIN(x,y) (x>y?y:x)
#define MINTH(x,y,z) (x>y?(y>z?z:y):(x>z?z:x))
long p[6]={0,},mi;
int main(){
	int t,cnt=0;
	scanf("%d",&t);
	int dp[t][3]={0,},i[t][3];
	for(int n=0;n<t;n++){
		scanf("%d%d%d",&i[n][0],&i[n][1],&i[n][2]);
	}
	//initialization
	for(int n=0;n<3;n++) dp[0][n]=i[0][n];
	//dp
	for(int n=1;n<t;n++){
		dp[n][0]=MIN(dp[n-1][1]+i[n][0],dp[n-1][2]+i[n][0]);
		dp[n][1]=MIN(dp[n-1][0]+i[n][1],dp[n-1][2]+i[n][1]);
		dp[n][2]=MIN(dp[n-1][1]+i[n][2],dp[n-1][0]+i[n][2]);
	}
	printf("%d",MINTH(dp[t-1][0],dp[t-1][1],dp[t-1][2]));
}