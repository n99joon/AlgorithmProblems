#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int tc;
	ll n;

		cin >> n;
		pair<ll,ll> arr[n+1];
		ll mid[n+1][n+1], dp[n+1][n+1];
		
		
		fill_n(&dp[0][0],(n+1)*(n+1),0);
		fill_n(&mid[0][0],(n+1)*(n+1),0);
		//fill_n(sum,n+1,0);
		fill_n(arr,n+1,make_pair(0,0));
		
		for(int i=0;i<n;i++){
			cin >> arr[i].first >> arr[i].second;
			/*
			if(i==0){
				sum[0].first=arr[0].first;
				sum[0].second=arr[0].second;
			}
			else if(i>0){
				sum[i].first=sum[i-1].first;
				sum[i].second=arr[i].second;
			}
			*/
			mid[i][i]=i;
		}
		
		for(int j=1;j<n;j++){
			int i=0;
			int y=j;
			while(i<n-1 && y<=n-1){
				dp[i][y]=2e18;
				
				for(ll m=i;m<y;m++){
					ll val=dp[i][m]+dp[m+1][y]+arr[i].first*arr[m].second*arr[y].second;//(i,m) + (m+1,y) dp value
	                if(val<dp[i][y])mid[i][y]=m;
					dp[i][y]=min(dp[i][y],val);
				}
				i++;
				y++;
			}
				
		}
		
		cout << dp[0][n-1] << endl;	
	
}