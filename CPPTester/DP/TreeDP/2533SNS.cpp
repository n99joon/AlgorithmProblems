#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 1000001
#define INF 1e9
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};
//17472
vector<int> edge[MAX];
int dp[MAX][2];
int n,r,q,x,y;

void fin(int prt,int cur){
	for(int t : edge[cur]){
		if(t==prt)continue;
		fin(cur,t);
		dp[cur][0]+=dp[t][1];
		dp[cur][1]+=min(dp[t][0],dp[t][1]);
	}
	return;
}
int main(){
	fastio;
	cin >> n;
	ffor(i,MAX)dp[i][1]=1;
	ffor(i,n-1){
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	fin(1,1);
	//forr(i,9)cout << dp[i][0] << " " <<dp[i][1]<<endl;
	
	cout << min(dp[1][0],dp[1][1]);
}