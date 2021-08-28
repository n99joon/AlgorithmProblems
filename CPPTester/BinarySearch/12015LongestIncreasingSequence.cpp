#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
using namespace std;
ll n,r;

ll binary(ll num, ll size, ll dp[]){
	ll ret=-1;
	ll left=0;
	ll right = size;
	while(left<=right){
		ll mid = (left+right)/2;
		if(dp[mid] < num){
			left = mid+1;
		}else{
			ret=mid; 
			right = mid -1;
		}
	}
	return ret;
}
int main() {
	fastio;
	cin >> n;
	ll arr[n];
	ll dp[n];
	ll idx=0;
	for(ll i = 0; i< n; i++){
		cin >> arr[i];
		if(i==0 || arr[i]>dp[idx-1]){
			dp[idx]=arr[i];
			idx++;
		}else {
			ll ret = binary(arr[i],idx,dp);
			if(ret!=-1)dp[ret]=arr[i];
		}
	}
	cout << idx;
}
