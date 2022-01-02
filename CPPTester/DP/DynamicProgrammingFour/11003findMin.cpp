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
//#define mod 1000000007LL //1e9+7
#define mod 9901
using namespace std;


int main(){
	fastio;
	deque<pii>dq;
	int n,l;
	cin >> n >> l;
	vector<int>inp(n);
	ffor(i,n){
		cin >> inp[i];
	}
	
	ffor(i,n){
		while(!dq.empty() && dq.front().se<=i-l){
			dq.pop_front();
		}
		while(!dq.empty() && dq.back().fi>=inp[i]){
			dq.pop_back();
		}
		dq.push_back({inp[i],i});
		cout<<dq.front().fi<<" ";
	}
}
//MCMF solve!