#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
using namespace std;

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int> arr;
	int prime[n+1]={0}; //0=prime
	for(int i=2;i*i<=n;i++){
		if(prime[i])continue;
		for(int j=i+i;j<=n;j+=i){
			prime[j]=1;
		}
	}
	
	for(int i=2;i<=n;i++){
		if(!prime[i]){
			//cout << i << " ";
			arr.push_back(i);
		}
	}
	
	int num = arr.size();
	if(num==0){
		cout << 0;
		return 0;
	}
	int i=0,j=0,cnt=0;
	ll sum=arr[0];
	while(j<num){
		if(sum==n){
			//cout << i << " " << j <<endl;
			cnt++;
			sum-=arr[i++];
		}else if(sum<n){
			if(j<num-1){
				sum+=arr[++j];
			}
			else break;
		}else{
			sum-=arr[i++];
		}
		if(i>j && i<num){
			j=i;
			sum+=arr[i];
		}	
	}
	cout << cnt;
}