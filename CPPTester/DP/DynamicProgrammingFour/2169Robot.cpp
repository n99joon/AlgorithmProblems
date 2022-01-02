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
#define mx 1002
using namespace std;
int dp[mx][mx][2];//dp[N][M][0=L, 1=R];
int inp[mx][mx];
int n,m;
int xm[] = {-1,1,0};
int ym[] = {0,0,1};

void calc(int n){
	//cur is right flow
	forr(i,m){
		dp[n][i][1]=max(max(dp[n-1][i][0],dp[n][i-1][1]),dp[n-1][i][1])+inp[n][i];
	}
	//cur is left flow
	for(int i=m;i>0;i--){
		dp[n][i][0]=max(max(dp[n-1][i][1],dp[n][i+1][0]),dp[n-1][i][0])+inp[n][i];
	}
}

int main(){
	fastio;
	cin >> n >> m;
	ffor(i,n+2)ffor(j,m+2)ffor(k,2){
		dp[i][j][k]=-1e9;
	}
	forr(i,n){
		forr(j,m){
			cin >> inp[i][j];
		}
	}
	dp[1][1][1]=inp[1][1];
	for(int i=2;i<=m;i++){
		dp[1][i][1]=dp[1][i-1][1]+inp[1][i];
	}
	
	for(int i=2;i<=n;i++){
		calc(i);
	}
	cout << dp[n][m][1];
}