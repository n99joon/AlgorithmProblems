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
int n;
db dp[1000001];
int main(){
	fastio;
	cin >> n;
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		forr(j,6){
			if(i-j>=0)dp[i]+=(1+dp[i-j])*(1.0/6);
			else dp[i]+=1.0/6;
		}
	}
	cout << fixed << setprecision(10) << dp[n]<<endl;
}