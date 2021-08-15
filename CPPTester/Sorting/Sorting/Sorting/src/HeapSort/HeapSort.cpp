#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
using namespace std;
int n,k;
vector<int> a;
//if i is larger , swap
int comp(int i, int j){
	int ret = -1;
	if(a[i]>a[j]){
		swap(a[i],a[j]);
		ret = j;
	}
	return ret;
}

void heapify(int i){
	//if the left child node > size then return
	if(i*2>=a.size())return;
	int m;
	//find min child
	if(i*2+1<a.size()){
		//m = index of smaller child
		m=a[i*2]>a[i*2+1]?i*2+1:i*2;
	}else{
		m = i*2;
	}
	//compare 
	int idx = comp(i,m);
	if(idx==-1) return;
	else heapify(idx);
}


void makeHeap(){
	int h = (int)log2(n);
	 for(int i=pow(2,h)-1;i>=1;i--){
		 heapify(i);
	 }
}

void heapSort(){
	makeHeap();
	
	cout << endl;
	while(a.size()>1){
		cout << a[1] << " ";
		a[1]=a[a.size()-1];
		a.pop_back();
		heapify(1);
	}
	
	
}

//Insertion Sort / Time = Best = O(n), avg, worst=O(n^2), Spcae = O(n)
int main() {
	fastio;
	a.push_back(0);
	cin >> n;
	int t;
	for(int i=1;i<=n;i++){
		cin >> t;
		a.push_back(t);
	}
	heapSort();
}
//https://ratsgo.github.io/data%20structure&algorithm/2017/09/27/heapsort/
//make heap comparison
/*
1. insert node one by one 
heapify = O(log n)
# of nodes = n
: O(n log n)
2. heapify floor by floor
each node does two comparison + one swap max
do it for n/2 nodes
: O(n/2 * 3) = O(n)
*/