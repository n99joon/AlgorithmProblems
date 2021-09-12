#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define MAX 10001
using namespace std;

int ans = 0;
int idx;
bool vstd[MAX];
vector<pii> edge[MAX];

void dfs(int nd , int dist){
	for(int i=0;i<edge[nd].size();i++){
		int to = edge[nd][i].first;
		if(vstd[to])continue;
		int c = edge[nd][i].second;
		if(dist+c>ans){
			idx=to;
			ans = dist+c;
		}
		vstd[to]=1;
		dfs(to,dist+c);
	}
}

int main(){
	int n,x,y,k;
	cin >> n;
	if(n==1){
		cout << 0;
		return 0;
	}
	ffor(i,n){
		cin >> x >> y >> k;
		edge[x].push_back({y,k});
		edge[y].push_back({x,k});
	}
	vstd[1]=1;
	dfs(1,0);
	ans = 0;
	fill(vstd,vstd+MAX,0);
	vstd[idx]=1;
	dfs(idx,0);
	cout << ans << endl;
}