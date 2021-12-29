#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define pll pair<long long, long long>
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
	int n,m,a,b;
	cin >> n >>m;
	//m+=1;
	
	ll ans=0,tot=m;
	vector<pii> reverse;
	ffor(i,n){
		cin >> a >> b;
		if(b<a){
			reverse.push_back({b,a});
		}
	}
	sort(reverse.begin(),reverse.end());
	int fr=reverse[0].fi, to=reverse[0].se;
	ffor(i,reverse.size()){
		if(reverse[i].fi>to){
			ans+=to-fr;
			fr = reverse[i].fi;
			to = reverse[i].se;
			continue;
		}
		to=max(to,reverse[i].se);
	}
	ans += to-fr;
	tot+=2*ans;
	cout << tot;
}