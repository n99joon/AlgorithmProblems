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

int main(){
	fastio;
	int n,d;
	ll ans=-1e9;
	cin >> n >> d;
	vector<int> inp(n+1);
	vector<ll> dp(n+1); // dp[i] = max total until i (inclusive)
	ffor(i,n){
		cin >> inp[i];
	}
	deque<pair<ll,int>> deq; //{dp[i],idx}
	deq.push_back({0,0});
	ffor(i,n){
		while(!deq.empty() && deq.front().se < i-d){
			deq.pop_front();
		}
		dp[i] = inp[i];
		if(!deq.empty()) dp[i]+=max(0LL,deq.front().fi);
		//arr[i] += DQ.empty() || arr[DQ.front()] < 0 ? 0 : arr[DQ.front()];
		if(dp[i]>0){
			while(!deq.empty() && deq.back().fi <= dp[i] ){
				deq.pop_back();
			}
			deq.push_back({dp[i],i});
		}
		ans=max(ans,dp[i]);
	}
	cout << ans;
}
// faster -> inp = no need just input in dp. 
// use index only for deque & get value from dp[idx]