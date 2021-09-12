#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long

using namespace std;

int main() {
	int n;
	cin >> n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	//for(int i=0;i<n;i++) cout << arr[i] << " ";
	//cout << endl;
	ll mini = 3e9;
	ll ans[3];
	int flag=0;
	for(int k=1;k<n-1;k++){
		int i=0;
		int j=n-1;
		while(i<k && j>k){
			ll sum = arr[i]+arr[j]+arr[k];
			ll sumabs=abs(sum);
			if(mini > sumabs){
				mini=sumabs;
				ans[0]=i;
				ans[1]=k;
				ans[2]=j;
			}
			if(sum==0){
				flag=1;
				break;
			}
			else if(sum>0)j--;
			else i++;
		}
		if(flag) break;
	}
	cout << arr[ans[0]] << " " << arr[ans[1]] << " " << arr[ans[2]];
}