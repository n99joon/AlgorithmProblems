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
#define mod 1000000007
#define ofs (2*1e5+1)
#define mx (4*1e5+1)
using namespace std;


struct FWT{
	vector<int> fwt;
	int n;
	FWT(){
		this -> n = 4*1e5+1;
		fwt.resize(4*1e5+2,0);
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
int main(){
	fastio;
	int n,a,b;
	ull ans=0;
	cin >> n;
	vector<pii> inp(n);
	FWT * smaller = new FWT(); //normal
	
	ffor(i,n){
		cin >> a >> b;
		inp[i].se = a+ofs;
		inp[i].fi = b+ofs;
		smaller->add(inp[i].se,1);
	}
	sort(inp.begin(),inp.end());
	/*
	for(auto k : inp){
		cout << k.se << " & " << k.fi << endl;
	}*/
	ffor(i,n){
		int idx=0;
		while(i+idx < n && inp[i+idx].fi==inp[i].fi){
			smaller->add(inp[i+idx].se,-1);
			idx++;
		}
		idx--;
		ffor(j,idx+1){
			ans = (ans + (ull)smaller->query(inp[i+j].se-1)*(smaller->query(mx)-smaller->query(inp[i+j].se)))%mod;
		}
		i+=idx;
	}
	cout << ans;
}