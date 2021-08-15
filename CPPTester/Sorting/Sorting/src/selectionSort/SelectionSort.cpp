#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
using namespace std;

//selection sort / Time = O(n^2), Spcae = O(n)
int main() {
	fastio;
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	for(int i=0;i<n-1;i++){
		int min=a[i];
		for(int j=i+1;j<n;j++){
			if(a[j]<min){
				min = a[j];
				swap(a[i],a[j]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}

//https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html