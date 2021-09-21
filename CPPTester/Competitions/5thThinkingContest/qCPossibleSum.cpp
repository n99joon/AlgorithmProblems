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
using namespace std;


vector<bool> dp;
int n,x;
ull inp[21];
ull cnt=0;
ull cur=0;

void dfs(int idx){
	if(idx==n) return;
	//cout << idx << " " << cur << endl;
	cur+=inp[idx];
	if(dp[cur]==false){
		dp[cur]=1;
		cnt++;
	}
	dfs(idx+1);
	cur-=inp[idx];
	dfs(idx+1);
}

int main(){
	ull sum=0;
	cin >> n;
	ffor(i,n){cin>>inp[i];sum+=inp[i];}
	dp.resize(sum+1);
	fill(dp.begin(),dp.end(),false);
	dfs(0);
	cout << sum-cnt;
}