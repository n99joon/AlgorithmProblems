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
	ull dp[n+1];
	int ans[n+1],vstd[n+1]={0}; //dp=cost so far, ans = node before
	fill(dp,dp+n+1,1e9);
	fill(ans,ans+n+1,-1);
	vector<pii> edge[n+1];
	int s,e,c;
	for(int i=0;i<m;i++){
		cin >> s >> e >> c;
		if(s==e)continue;
		edge[s].push_back({c,e});
	}
	int start,end;
	cin >> start >> end;
	int visited=0;
	dp[start]=0;
	int k = start;
	vstd[k]=1;
	while(visited<n){
		int min=1e9;
		//update adjacent node's distance
		for(int i=0;i<edge[k].size();i++){
			int next=edge[k][i].second;
			int cost=edge[k][i].first;
			if(dp[next]>dp[k]+cost){
				dp[next]=dp[k]+cost;
				ans[next]=k;
			}
		}
			
		//find the minimum node
		for(int i=1;i<=n;i++){
			if(dp[i]<min && vstd[i]==0){
				min=dp[i];
				k=i;
			}
		}
		vstd[k]=1;
		//cout << "k is " << k;
			//if node == end return
		if(k==end)break;
		visited++;
	}
	cout << dp[end] << endl;
	
	//count # of cities visited & output cities
	int cntr=0;
	vector<int> ret;
	k=end;
	while(k!=start){
		ret.push_back(k);
		k=ans[k];
		cntr++;
	}
	ret.push_back(start);
	reverse(ret.begin(),ret.end());
	cout << cntr+1 << endl;
	for(auto p:ret)cout << p << " ";
}