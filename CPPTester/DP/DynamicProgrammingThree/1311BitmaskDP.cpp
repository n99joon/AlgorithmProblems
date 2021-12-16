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
using namespace std;
int n;
int dp[1<<21];
int cost[21][21];
int solv(int bm,int idx){
	if(idx==n)return 0;
	int & ret = dp[bm];
	if(ret!=0)return ret;
	ret = 1e9;
	ffor(i,n){
		if(1 & bm >> i)continue;
		ret = min(ret, solv(bm | 1<<i,idx+1)+cost[idx][i]);
	}
	return ret;
}
int main(){
	fastio;
	cin >> n;
	ffor(i,n)ffor(j,n)cin >> cost[i][j];//i=#번째사람,J=일
	cout<<solv(0,0);
}