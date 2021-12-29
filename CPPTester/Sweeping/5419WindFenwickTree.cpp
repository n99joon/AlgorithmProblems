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


struct FWT{
	vector<int> fwt;
	int n;
	FWT(int n){
		this-> n = n;
		fwt.resize(n+1,0);
	}
	
	void add(int idx, int k){
		while(idx<=n){
			fwt[idx]+=k;
			idx+=-idx & idx;
		}
	}
	int query(int idx){
		int ret = 0;
		while(idx!=0){
			ret+=fwt[idx];
			idx&=idx-1;
		}
		return ret;
	}
};
//pll = <y,x>
bool comp(const pll a, const pll b){
	if(a.se == b.se)return a.fi>=b.fi;
	return a.se < b.se;
}
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		ll ans =0;
		ll x,y;
		cin >> n;
		FWT * root = new FWT(n);
		vector<pll> inp(n);//compressed input (inp[num] = compressed y)
		
		ffor(i,n){
			cin >> x >> y;
			inp[i]={y,x};
		}
		
		sort(inp.begin(),inp.end());
		ll prev = inp[0].fi;
		int cur=0;
		ffor(i,n){
			if(inp[i].fi==prev){
				inp[i].fi=cur+1;
				root->add(cur+1,1);
			}else{
				prev = inp[i].fi;
				inp[i].fi=i+1;
				cur = i;
				root->add(i+1,1);
			}
		}
		sort(inp.begin(),inp.end(),comp);
		//traverse from leftmost point
		ffor(i,n){
			root->add(inp[i].fi,-1);
			ans += root->query(inp[i].fi);
		}
		cout << ans << endl;
	}
}