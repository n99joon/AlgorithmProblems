#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
using namespace std;

//Insertion Sort / Time = Best = O(n), avg, worst=O(n^2), Spcae = O(n)
int main() {
	fastio;
	int n,k;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++){
		cin >> k;
		pq.push(k);
	}
	
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}

}
