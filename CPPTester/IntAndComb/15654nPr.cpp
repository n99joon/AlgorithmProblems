#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int n,r;
int main() {
	fastio;
	cin >> n >> r;
	int ar[n];
	for(int i=0;i<n;i++){
		cin >> ar[i];
	}
	sort(ar,ar+n);
	do{
		for(int i=0;i<r;i++){
			cout << ar[i] << " ";
		}
		cout << endl;
		reverse(ar+r,ar+n);
	}while(next_permutation(ar,ar+n));
}
