#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
using namespace std;
ll n,r;
ll findLess(ll x){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		cnt+=min(x/i,n);
	}
	return cnt;
}
int main() {
	fastio;
	cin >> n >> r;
	
	ll left=1;
	ll right=n*n;
	ll ans=1;
	while(left<=right){
		ll mid = (left+right)/2;
		if(findLess(mid)<r){//# of less & equal elements is less than index
			
			left=mid+1;
		}else{
			right=mid-1;
			ans=mid;
		}
	}
	cout << ans;
}
