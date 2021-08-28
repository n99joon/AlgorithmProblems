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
	ll arr[n]; //input
	ll dp[n]; //the largest number when length of LIS is n
	ll idx=0; 
	ll pos[n]={0};
	for(ll i = 0; i< n; i++){
		cin >> arr[i];
		if(i==0 || arr[i]>dp[idx-1]){
			dp[idx]=arr[i];
			pos[i]=idx;
			idx++;
		}else{
			ll ret = binary(arr[i],idx,dp);
			if(ret!=-1){
				dp[ret]=arr[i];
				pos[i]=ret;
			}
		}
	}
	cout << idx << endl;
	idx--;
	stack<ll> out;
    for(int i=n-1;i>=0;i--){
        if(pos[i]==idx) {
			out.push(arr[i]);
			idx--;
		}
		if(idx==-1) break;
    }
	while(!out.empty()){
		cout << out.top() << " ";
		out.pop();
	}
	cout << endl;
}