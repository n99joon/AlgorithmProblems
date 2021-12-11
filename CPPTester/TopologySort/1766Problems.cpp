#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100000000ULL
#define fi first
#define se second
#define eb 0.000000001
#define mod 1000000003
using namespace std;


int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	vector<int> ptt[n+1];
	vector<int> ptd(n+1,0);
	while(m--){
		int fr,to;
		cin >> fr >> to;
		ptt[fr].push_back(to);
		ptd[to]++;
	}
	
	priority_queue<int,vector<int>,greater<int>> pq;
	forr(i,n){
		if(ptd[i]==0){
			pq.push(i);
		}
	}
	
	while(!pq.empty()){
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		
		for(int i=0;i<ptt[cur].size();i++){
			int k = ptt[cur][i];
			if(--ptd[k]==0){
				pq.push(k);
			}
		}
	}
	return 0;
}
