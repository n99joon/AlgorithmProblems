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
	int m, k, n;
	cin >> n>>m>>k;
	vector<int> inp(n+1);
	forr(i,n){
		cin>>inp[i];
	}
	vector<int> rock(k+1);
	forr(i,k){
		cin >> rock[i];
	}
	vector<ull> canSave(k+1,0);
	forr(i,k){
		int till;
		if(i==k)till=n;
		else till=rock[i+1]-1;
		for(int j=rock[i];j<=till;j++){
			canSave[i]+=inp[j];
		}
	}
	priority_queue<pair<ull,int>>pq;//canSave , -idx
	forr(i,k){
		pq.push({canSave[i],-rock[i]});
	}
	int taken  = 0;
	vector<int> ans;
	while(taken < m){
		taken++;
		ans.push_back(-pq.top().se);
		//cout<<-pq.top().se<<endl;
		pq.pop();
	}
	sort(ans.begin(),ans.end());
	for(auto p : ans){
		cout << p << endl;
	}
}