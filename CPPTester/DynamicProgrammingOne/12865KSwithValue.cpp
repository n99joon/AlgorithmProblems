#include <cstdio>
#include <iostream>
using namespace std;
#define MIN(x,y) (x>y?y:x)

//knapsack with value
int main(){
	int n,W;
	scanf("%d%d",&n,&W);
	int maxV=0;
	
	int it[n][2];//0=w, 1=v
	int max=0;
	for(int i=0;i<n;i++){
		scanf("%d%d",&it[i][0],&it[i][1]);
		maxV+=it[i][1];
	}
	int dp[n+1][maxV+1]={0,};
	for(int j=0;j<=n;j++)
	for(int i=0;i<maxV+1;i++){
		dp[j][i]=0;
	}
	
	for(int i=0;i<n;i++){
        
		for(int j=0;j<=maxV;j++){
			if(j>=it[i][1]){
			//can make including ith item
			if(j==it[i][1] || dp[i][j-it[i][1]]!=0){
				//if just the item
				if(dp[i][j-it[i][1]]==0)dp[i+1][j]=it[i][0];
				//if shd include the previous
				else if(dp[i][j]==0)dp[i+1][j]=dp[i][j-it[i][1]]+it[i][0];
				else dp[i+1][j]=MIN(dp[i][j-it[i][1]]+it[i][0],dp[i][j]);
			}
			//can make w/o ith item
			else if(dp[i][j]!=0) dp[i+1][j]=dp[i][j];
			//can't make
			else dp[i+1][j]=0;
			} else dp[i+1][j]=dp[i][j];
			if(dp[i+1][j]!=0 && j>max && dp[i+1][j]<=W)max=j;
			
		}
	}
	
	printf("%d",max);
}