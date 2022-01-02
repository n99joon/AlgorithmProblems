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

int isP[2501][2501];
int dp[2501];
string s;
int isPal(int i, int j){
	int & ans = isP[i][j];
	if(ans!=-1)return ans;
	if(i>=j)return ans=1;
	if(s[i]!=s[j])return ans=0;
	return ans=isPal(i+1,j-1);
}
int main(){
	fastio;
	memset(isP,-1,sizeof isP);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	cin >> s;
	forr(i,s.length()){
		dp[i]=dp[i-1]+1;
		for(int j = 1; j<i;j++){
			if(!isPal(j-1,i-1))continue;
			dp[i]=min(dp[i],dp[j-1]+1);
		}
	}
	cout<<dp[s.length()];
}
//더빨리
//https://www.acmicpc.net/source/9627889