#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100000000ULL
#define fi first
#define se second
#define eb 0.000000001
#define mod 1000000003
using namespace std;

int dp[100001];
int n,k;

int main(){
	fastio;
	cin >> n >> k;
	vector<int> coins(n);
	ffor(i,n) cin >> coins[i];
	fill(dp,dp+100001,100001);
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = coins[i]; j <= k; j++){
			dp[j] = min(dp[j],dp[j-coins[i]]+1);
		}
	}
	if(dp[k] == 100001) cout << -1;
	else cout << dp[k];
	
	
}