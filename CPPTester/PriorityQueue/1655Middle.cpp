#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int main() {
	fastio;
	priority_queue<int> pqMax;
	priority_queue<int,vector<int>,greater<int>> pqMin;
	int size=0,n,k;
	cin >> n;
	while(n--){
		cin >> k;
		if(size&1){
			if(k<pqMax.top()){
				pqMin.push(pqMax.top());
				pqMax.pop();
				pqMax.push(k);
				cout << pqMax.top() << endl;
			}else {
				pqMin.push(k);
				cout << pqMax.top() << endl;
			}
		}else{
			if(pqMax.empty()){
				pqMax.push(k);
				cout << k << endl;
			} else if(k>pqMin.top()){
				pqMax.push(pqMin.top());
				pqMin.pop();
				pqMin.push(k);
				cout << pqMax.top() << endl;
			} else {
				pqMax.push(k);
				cout << pqMax.top() << endl;
			}
		}
		size++;
	}
}
