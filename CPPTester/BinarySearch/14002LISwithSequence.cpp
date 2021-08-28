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
    if(n==1){
         cout << 1;
        cin >> n;
        cout << endl << n << endl;
        return 0;
    }
	ll arr[n];
	ll dp[n];
	ll idx=0;
	vector<ll> LIS[n];
	for(ll i = 0; i< n; i++){
		cin >> arr[i];
		if(i==0 || arr[i]>dp[idx-1]){
			dp[idx]=arr[i];
			LIS[idx].resize(idx);
			for(int j=0;j<idx;j++){
				LIS[idx][j]=LIS[idx-1][j];
			}
			LIS[idx].push_back(arr[i]);
			idx++;
		}else{
			ll ret = binary(arr[i],idx,dp);
			if(ret!=-1){
				dp[ret]=arr[i];
				for(int j=0;j<ret;j++){
					LIS[ret][j]=LIS[ret-1][j];
				}
				LIS[ret][ret]=dp[ret];
				//cout << "reach here with " << ret << " and " << dp[ret] << endl;
			}
		}
	}
	cout << idx << endl;
    for(int i=0;i<idx;i++){
        cout << LIS[idx-1][i] << " ";
    }
	cout << endl;
}