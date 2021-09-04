#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;

int main() {
	fastio;
	int n,m;
	cin >> n >> m;
	int dp[n+1][n+1],ans[n+1][n+1]; //dp=cost so far, ans = node between(0=unvisited,-1=no node between)
	fill_n(&dp[0][0],(n+1)*(n+1),1e9);
	fill_n(&ans[0][0],(n+1)*(n+1),0);
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	//vector<pii> edge[n+1];
	int s,e,c;
	for(int i=0;i<m;i++){
		cin >> s >> e >> c;
		if(s==e)continue;
		//edge[s].push_back({c,e});
		if(dp[s][e]>c){
			dp[s][e]=c;
		    ans[s][e]=-1;
		}
	}
	
	
	
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				if(i==j)continue;
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
					ans[i][j]=k;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==1e9)cout << 0 << " ";
			else cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j || dp[i][j]==1e9 || ans[i][j]==0){
				cout << 0 << endl;
				continue;
			}
			int cnt=0;
			vector<int> ret;
			stack<pii> dfs;
			dfs.push({i,j});
			while(!dfs.empty()){
				pii s = dfs.top();
				dfs.pop();
				//[o][t]
				int o = s.first; 
				int t = s.second;
				int mid = ans[o][t];
				if(mid==-1){
					ret.push_back(o);
					continue;
				}
				dfs.push({mid,t});
				dfs.push({o,mid});
			}
			cout << ret.size()+1 << " ";
			//for loop
			for(int a:ret)cout << a << " ";
			cout << j << endl;
		}
	}
}