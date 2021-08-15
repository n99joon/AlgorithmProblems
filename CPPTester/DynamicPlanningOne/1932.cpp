#include <cstdio>
#define MAX(x,y) (x>y?x:y)
int main(){
	int t;
	scanf("%d",&t);
	int dp[501][501]={0,},n[501][501];
	for(int i=0;i<t;i++){
		for(int j=0;j<i+1;j++){
			scanf("%d",&n[i][j]);
			if(i==0) dp[i][j]=n[i][j];
			else if(j==0) dp[i][j]=dp[i-1][j]+n[i][j];
			else if(j==i) dp[i][j]=dp[i-1][j-1]+n[i][j];
			else {
				dp[i][j]=MAX(dp[i-1][j],dp[i-1][j-1])+n[i][j];
			}
		}
	}
	int max=0;
	for(int i=0;i<t;i++){
		if(dp[t-1][i]>max)max=dp[t-1][i];
	}
	printf("%d",max);
}