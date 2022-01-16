#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define uint long
#define endl '\n'
using namespace std;

class Compare{
	public:
	bool operator()(uint a, uint b){
			if(abs(a)<abs(b))return 0;
			else{
				if(abs(a)==abs(b))return a<b?0:1;
				return 1;
			}
	}
};
		


int main() {
	fastio;
	priority_queue<uint,vector<uint>,Compare> pq;
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
