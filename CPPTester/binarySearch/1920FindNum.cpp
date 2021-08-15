#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define uint unsigned int
#define endl '\n'
using namespace std;

int main() {
	fastio;
	uint n,k;
	cin>>n;
	vector<uint> h;
	while(n--){
		make_heap(h.begin(),h.end());
		cin >> k;
		if(k==0){
			if(h.size()==0)cout<<0<<endl;
			else {
				cout<<h.front()<<endl;
				pop_heap(h.begin(),h.end());
				h.pop_back();
			}
		}
		else{
			h.push_back(k);
			push_heap(h.begin(),h.end());
		}
	}
}
