#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100001
#define INF 1e9
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};
//17472
vector<int> edge[MAX];
int dp[MAX]={0};
int n,r,q,x,y;

int fin(int prt,int cur){
	for(int t : edge[cur]){
		if(t==prt)continue;
		dp[cur]+=fin(cur,t);
	}
	return dp[cur]+=1;
}
int main(){
	fastio;
	cin >> n >> r >> q;
	ffor(i,n-1){
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dp[r]=0;
	x=fin(r,r);
	ffor(i,q){
		cin >> x;
		cout << dp[x] << endl;
	}
}