#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int n,x,max=0,k;
	ll ret=0;
	cin >> n;
	int arr[1000001]={0};
	for(int i=0;i<n;i++){
		cin >> k;
		arr[k]++;
		if(k>max)max=k;
	}
	
	cin >>x;
	
	int i=0,j=max;
	while(i<j){
		int sum=i+j;
		if(sum==x){
			ret+=arr[i]*arr[j];
			i++;
			j--;
		}
		else if(sum<x){
			i++;
		}
		else{
			j--;
		}
	}
	cout << ret;
}