#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int n,k;
	cin >> n;
	int arr[n+1]={0},dp[n+1][n+1]={0};
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		dp[i][i]=1;
	}
	for(int i=1;i<=n;i++){//length of str
		for(int j=1;j+i<=n;j++){
			if(i==1){
				dp[j][j+i]=arr[j]==arr[j+i];
			}
			else{
				dp[j][j+i]=dp[j+1][j+i-1] & (arr[j]==arr[j+i]);
			}
		}
	}
	cin >> k;
	for(int i=1;i<=k;i++){
		int n,m;
		cin >> n >> m;
		cout << dp[n][m] << endl;
	}
}