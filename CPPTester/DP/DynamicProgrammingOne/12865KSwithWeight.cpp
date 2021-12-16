#include <cstdio>
#include <iostream>
using namespace std;
#define MAX(x,y) (x>y?x:y)
int main(){
	int n,W;
	scanf("%d%d",&n,&W);
	int dp[n+1][W+1]={0,};
	for(int i=0;i<W+1;i++){
		dp[0][i]=0;
	}
	
	int it[n][2];//0=w, 1=v
	int max=0;
	for(int i=0;i<n;i++){
		scanf("%d%d",&it[i][0],&it[i][1]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=W;j++){
			if(j<it[i][0])dp[i+1][j]=dp[i][j];
			else dp[i+1][j]=MAX(dp[i][j-it[i][0]]+it[i][1],dp[i][j]);
			if(dp[i+1][j]>max)max=dp[i+1][j];
		}
	}
	
	printf("%d",max);
}