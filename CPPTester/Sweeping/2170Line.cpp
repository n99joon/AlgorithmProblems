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
	int n;
	ll a,b,ans=0;
	cin >> n;
	vector<pll> inp(n);
	ffor(i,n){
		cin >>inp[i].fi >> inp[i].se;
	}
	sort(inp.begin(),inp.end());
	int end =0;
	ll fr=inp[0].fi,to=inp[0].se;
	while(end<n){
		//last
		if(end==n-1){
			//overlaps
			if(inp[end].fi<=to){
				ans+=max(inp[end].se,to)-fr;
				break;
			}
		}
		//no overlap
		if(inp[end].fi>to){
			ans+=to-fr;
			fr = inp[end].fi;
			to = inp[end].se;
			continue;
		}
		to=max(to,inp[end].se);
		end++;
	}
	cout << ans;
}