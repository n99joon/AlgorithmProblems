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

//dp[i] = # of available players to take to another team/
int dp[90001];
int main(){
	fastio;
	int n,sum=0,minD=1e9;
	cin >> n;
	int inp[n],last;
	ffor(i,n){
		cin >> inp[i];
		sum += inp[i];
	}
	last = sum+45000;
	dp[sum+45000]=n/2;
	ffor(i, n){
		for(int j=sum+45000;j>=last;j++){
			if(dp[j]>0){
				dp[j-inp[i]]=max(dp[j-inp[i]],dp[j]-1);
				
			}
		}
	}
}