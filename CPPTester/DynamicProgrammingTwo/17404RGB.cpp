#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define d double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
using namespace std;


int main(){
	int n;
	cin >> n;
	int dp[n][3];
	int cost[n][3];// R G B
	ffor(i,n){
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; //R G B
	}
	
	int ans=2e9;
	ffor(i,3){
		ffor(k,3){
			if(k==i)dp[0][k]=cost[0][k];
			else dp[0][k]=2e9;
		}
		for(int j=1;j<n;j++){
				dp[j][0]=min(dp[j-1][1],dp[j-1][2])+cost[j][0];
				dp[j][1]=min(dp[j-1][0],dp[j-1][2])+cost[j][1];
				dp[j][2]=min(dp[j-1][1],dp[j-1][0])+cost[j][2];
		}
		ffor(k,3){
			if(k!=i){
				ans=min(ans,dp[n-1][k]);
			}
		}
	}
	cout << ans;
}