#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
using namespace std;
int n,k;
vector<int> a;

//MergeSort / Time = Best, avg, worst=O(n log n), Space = O(n) but not in place
void merge(int start, int mid, int end){
	vector<int> temp;
	int i=start;
	int j=mid+1;
	while(i<=mid && j<=end){
		if(a[i]<a[j]){
			temp.push_back(a[i++]);
		}else{
			temp.push_back(a[j++]);
		}
	}
	
	if(i>mid){
		while(j<=end)
			temp.push_back(a[j++]);
	}else{
		while(i<=mid)
			temp.push_back(a[i++]);
	}
	
	for(int t=start;t<=end;t++){
		a[t]=temp[t-start];
	}
}

void mergeSort(int start, int end){
	if(start<end){
		int mid=(start+end)/2;
		mergeSort(start,mid);
		mergeSort(mid+1,end);
		merge(start,mid,end);
	}
}

int main() {
	fastio;
	cin >> n;
	int t;
	for(int i=1;i<=n;i++){
		cin >> t;
		a.push_back(t);
	}
	mergeSort(0,n-1);
	
	for(auto i=a.begin();i!=a.end();i++){
		cout << *i << " ";
	}
}
