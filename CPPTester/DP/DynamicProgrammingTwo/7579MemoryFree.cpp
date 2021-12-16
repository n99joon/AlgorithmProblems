#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int n,m;
	cin >> n >> m;
	int mem[n],cost[n],sum=0;
	for (int i=0;i<n;i++){
		cin >> mem[i];
	}
	for (int i=0;i<n;i++){
		cin >> cost[i];
		sum+=cost[i];
	}
	int dp[sum+1]={0},temp[sum+1];
	
	for(int i=0;i<n;i++){
		copy(dp,dp+sum+1,temp);
		for(int j=cost[i];j<=sum;j++){
			temp[j]=max(dp[j],dp[j-cost[i]]+mem[i]);
		}
		copy(temp,temp+sum+1,dp);
	}
	for(int i=0;i<=sum;i++){
		if(dp[i]>=m){
			cout << i;
			break;
		}
	}
}