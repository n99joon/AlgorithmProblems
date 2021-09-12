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
	ll arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	int i=0,j=n-1;
	ll min=2e9+1, minA,minB;
	while(i<j){
		ll sum=arr[i]+arr[j];
		ll sumA=arr[i+1]+arr[j];
		ll sumB=arr[i]+arr[j-1];
		if(sum*sum < min*min){
			min=sum;
			minA=arr[i];
			minB=arr[j];
		}
		else if(sumA*sumA < sumB*sumB)i++;
		else j--;
	}
	cout << minA << " " << minB;
}