#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int tc;
	cin >> tc;
	ll n;
	while(tc--){
		cin >> n;
		ll dp[n+1][n+1],mid[n+1][n+1],sum[n+1],arr[n+1];
		
		fill_n(&dp[0][0],(n+1)*(n+1),0);
		fill_n(&mid[0][0],(n+1)*(n+1),0);
		fill_n(sum,n+1,0);
		fill_n(arr,n+1,0);
		
		for(int i=0;i<n;i++){
			cin >> arr[i];
			if(i==0){
				sum[0]=arr[0];
			}
			else if(i>0){
				sum[i]=sum[i-1]+arr[i];
			}
			mid[i][i]=i;
		}
		
		for(int j=1;j<n;j++){
			int i=0;
			int y=j;
			while(i<n-1 && y<=n-1){
				dp[i][y]=2e9;
				
				for(ll m=mid[i][y-1];m<=mid[i+1][y];m++){
	                if(dp[i][m]+dp[m+1][y]+sum[y]-sum[i]+arr[i]<dp[i][y])mid[i][y]=m;
					dp[i][y]=min(dp[i][y],dp[i][m]+dp[m+1][y]+sum[y]-sum[i]+arr[i]);
				}
				
				i++;
				y++;
			}
				
		}
		
		cout << dp[0][n-1] << endl;	
	}
}


/*
https://cse.hkust.edu.hk/~golin/Talks/Knuth_Yao_SODA05.pdf

http://web.cs.unlv.edu/bein/pubs/knuthyaotalg.pdf

https://js1jj2sk3.tistory.com/3

https://sexycoder.tistory.com/92
*/