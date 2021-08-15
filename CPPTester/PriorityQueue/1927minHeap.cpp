#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define uint unsigned int
#define endl '\n'
using namespace std;

int main() {
	fastio;
	priority_queue<int,vector<int>,greater<int>> pq;
	uint n,k;
	cin >> n;
	while(n--){
		cin >>k;
		if(k==0){
			if(pq.empty())cout<<"0\n";
			else{
				cout << pq.top()<< "\n";
				pq.pop();
			}
		}else {
			pq.push(k);
		}
	}
}
