#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
using namespace std;
int n;

int main() {
	fastio;
	cin >> n;
	if(n==1){
		cout << 0 << endl << 1;
		return 1;
	}
	int cnt=0;
	int dp[n+1]; //minimum after nth modification
	for(int i=0;i<n;i++){
		dp[i]=i-1;
	}
	dp[0]=1e9;
	for(int i=2;i<=n;i++){
		int a=dp[i-1];
		if(i%3==0)a=min(a,dp[i/3]);
		if(i%2==0)a=min(a,dp[i/2]);
		dp[i]=a+1;
	}
	cout << dp[n] << endl;
	vector<int> ret;
	
	int f = dp[n];
	int k = n;
	while(k>=1){
		if(f<1)break;
		ret.push_back(k);
		if(k%3==0){
			if(dp[k/3]==f-1){
				k/=3;
				f--;
				continue;
			}
		}
		if(k%2==0){
			if(dp[k/2]==f-1){
				k/=2;
				f--;
				continue;
			}
		}
		k-=1;
		f--;
	}
	
	for(auto t:ret)
		cout << t << " ";
	cout << 1;
	
}