#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define MAX 100001
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
	int n,x,y,k,p,d;
	cin >> n;
	
	ffor(i,n){
		cin >> k;
		while(1){
			cin >> p;
			if(p == -1)
				break;

			cin >> d;
			edge[k].push_back({p,d});
		}
	}
	vstd[1]=1;
	dfs(1,0);
	ans = 0;
	fill(vstd,vstd+MAX,0);
	vstd[idx]=1;
	dfs(idx,0);
	cout << ans << endl;
}