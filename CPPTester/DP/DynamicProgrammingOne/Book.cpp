#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
using namespace std;

int main() {
	fastio;
	int n,tc;
	cin >> tc;
	while(tc--){
		cin >> n;
		ll arr[n],dp[n],sum[n];//dp = cost so far, sum = 합친 종이두께
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			if(i==0){
				dp[0]=0;
				sum[0]=arr[0];
			}
			else if(i==1){
				dp[1]=arr[1]+arr[0];
				sum[1]=arr[1]+arr[0];
			}
			else{
				/*
				dp[i]=min(dp[i-1]+sum[i-1]+arr[i],dp[i-2]+sum[i-2]+arr[i-1]+arr[i]));//(1+2 3, 1 2+3)
				sum[i]=sum[i-1]+arr[i];*/
				
			}
		}
		cout << dp[n-1] << endl;
	}
}
//https://js1jj2sk3.tistory.com/3
//http://melonicedlatte.com/algorithm/2018/03/22/051337.html
//https://www.acmicpc.net/problem/11066