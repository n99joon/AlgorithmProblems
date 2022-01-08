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
vector<ll> psum; //psum[i] = psum until i (inclusive)
vector<ll> dp; // dp[i] = max total until i (inclusive)
int main(){
	fastio;
	int n,k,p;
	cin >> n >>k;
	psum.resize(n+1);
	forr(i,n){
		cin >> p;
		psum[i]=psum[i-1]+p;
	}
	dp.resize(n+1);
	deque<pair<ll,int>> dq;//value, idx
	//dp[1]=psum[1];
	//dq.push_back({0,0});
	dq.push_back({0,0});
	for(int i = 1;i<=n;i++){
		ll c = dp[i-1]-psum[i];
		//cout << c << endl;
		while(!dq.empty() && dq.front().se < i-k){
			dq.pop_front();
		}
		
		while(!dq.empty() && dq.back().fi <= c){
			dq.pop_back();
		}
		
		dq.push_back({c,i});
		dp[i]=dq.front().fi+psum[i];
	}
	/*
	while(!dq.empty()){
		cout << dq.front().fi << " ";
		dq.pop_front();
	}*/
	cout << dp[n]<<endl;
}