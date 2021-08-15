#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
using namespace std;

//Insertion Sort / Time = Best = O(n), avg, worst=O(n^2), Spcae = O(n)
int main() {
	fastio;
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n-i;j++){
			if(a[j-1]>a[j]){
				swap(a[j-1],a[j]);
			}
		}
	}
	
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
}