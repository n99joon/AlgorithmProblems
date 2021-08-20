#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;


int main() {
	fastio;
	int n;
	cin >> n;
	int dp[n],dist[n];
	
	for(int i=0;i<n;i++){
		cin >> dist[i];
		if(i==0)dp[i]=dist[i];
		else if(i==1)dp[i]=dp[0];
		else{
			dp[i]=min(dp[i-2]+dist[i-1],dp[i-1]+dist[i]);
		}
	}
	cout << dp[n-1];
}
