#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define INF 100000
using namespace std;
int n,k;
int dp[100001]={0};
int main() {
	fastio;
	cin >> n >> k;
	
	queue<int> bfs;
	bfs.push(n);
	fill_n(dp,100001,-1);
	dp[n]=100002;
	while(!bfs.empty()){
		int t = bfs.front();
		bfs.pop();
		if(t>2*n && t>2*k) continue;
		if(t==k){
			break;
		}
		
		if(t<k && t*2<=INF && dp[t*2]==-1){
			dp[2*t]=t;
			if(t*2==k)break;
			bfs.push(2*t);
		}
		if(t+1 <= INF && dp[t+1]==-1){
			dp[t+1]=t;
			if(t+1==k)break;
			bfs.push(t+1);
		}
		if(t-1>=0 && dp[t-1]==-1){
			dp[t-1]=t;
			if(t-1==k)break;
			bfs.push(t-1);
		}
	}
	int cnt=0;
	vector<int> ret;
	ret.push_back(k);
	while(k!=n){
		cnt++;
		ret.push_back(dp[k]);
		k=dp[k];
	}
	cout << cnt <<endl;
	
	
	reverse(ret.begin(),ret.end());
	for(auto x:ret)cout << x << " ";
	
}