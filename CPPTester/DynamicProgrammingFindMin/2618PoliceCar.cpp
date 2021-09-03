#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
int n,m;
int dp[1001][1001]={0};
int ans[1001][1001]={0};
pii cs[1001];

int findD(pii a, pii b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

void solv(int i, int j){
	if(i==n || j==n){
		dp[i][j]=0;
		return;
	}
	if(dp[i][j]!=-1)return;
	int maxC = max(i,j)+1;
	
	
	//first car goes
	pii t = (i==0?make_pair(1,1):cs[i]);
	solv(maxC,j);
	
	//second car goes
	pii p = ((j==0)?make_pair(m,m):cs[j]);
	solv(i,maxC);
	
	int temp=dp[maxC][j]+findD(cs[maxC],t);
	dp[i][j]=min(temp, dp[i][maxC]+findD(cs[maxC],p));
	if(dp[i][j]==temp)ans[i][j]=1;
	else ans[i][j]=2;
}

int main() {
	fastio;
	cin >> m >> n;
	
	for(int i=1;i<=n;i++){
		cin >> cs[i].first >> cs[i].second;
	}
	fill_n(&dp[0][0],1001*1001,-1);
	solv(0,0);
	cout << dp[0][0] << endl;
	
	int cnt = 1, i=0, j=0;
	while(cnt <= n){
		cout << ans[i][j] << endl;
		if(ans[i][j]==1)i=cnt++;
		else j=cnt++;
	}
}