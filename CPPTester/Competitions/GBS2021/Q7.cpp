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
vector<int> score;
vector<int> cur;

int dp[101][100002];
int main(){
	fastio;
	int n,m;
	cin >> n >> m; //n = tire, m = # student
	score.resize(n+1);
	cur.resize(n+1);
	int oppo =0;
	forr(i,n){
		cin >> score[i] >> cur[i];
		oppo+=score[i];
	}
	
	forr(i,n){
		for(int j=1;j<=m;j++){
			//if(j+cur[i]>m)break;
			//draw
			if(j<cur[i]){
				dp[i][j]=dp[i-1][j];
				continue;
			}
			dp[i][j]=max(dp[i][j],dp[i][j-1]);
			dp[i][j]=max(dp[i-1][j-cur[i]]+score[i],dp[i][j]);
			//win
			if(j>cur[i])dp[i][j]=max(dp[i-1][j-cur[i]-1]+score[i]*2,dp[i][j]);
			dp[i][j]=max(dp[i-1][j],dp[i][j]);
		}
	}
	/*
	cout<<dp[1][1]<<" "<<dp[1][2]<<" "<<dp[1][3]<<endl;
	cout<<dp[2][1]<<" "<<dp[2][2]<<" "<<dp[2][3]<<endl;
	cout<<dp[3][1]<<" "<<dp[3][2]<<" "<<dp[3][3]<<endl;
	*/
	/*
	ffor(i,n+1){
		forr(j,m){
			cout << dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	//cout << dp[n][m]<<endl;
	if(dp[n][m]>oppo)cout<<"W"<<endl;
	else if(dp[n][m]==oppo)cout<<"D"<<endl;
	else cout<<"L"<<endl;
}