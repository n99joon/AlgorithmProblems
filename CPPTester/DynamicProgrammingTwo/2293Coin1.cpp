#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int n,k;
	cin >> n >> k;
	ll arr[n+1],dp[10001]={0};
    dp[0]=1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i]>k) continue;
        else{
		    for(int j=arr[i];j<=k;j++){
			    dp[j]+=dp[j-arr[i]];
		    }
            
        }
	}
	
	cout << dp[k];
}