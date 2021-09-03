#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int n,s;
	cin >> n >> s;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int i=0,j=0,sum=arr[0],min=1e9;
	while(j<n){
		if(sum>=s){
			if(j-i+1<min)min=j-i+1;
			sum-=arr[i++];
		}else if(sum<s){
			if(j<n-1){
				sum+=arr[++j];
			}
			else break;
		}
		if(i>j && i<n){
			j=i;
			sum+=arr[i];
		}	
	}
	if(min==1e9)cout << 0;
	else cout << min;
}