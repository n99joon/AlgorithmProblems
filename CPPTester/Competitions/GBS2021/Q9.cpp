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
ull n,p,k;

ull convert(ull x){
	ull ret=x;
	ffor(i,2){
		ret*=x;
		ret%=p;
	}
	ret+=p;
	ret-=x*k;
	ret%=p;
	return ret;
}
int main(){
	fastio;
	cin >> n >> p >> k;
	ull ans = 0;
	vector<ull> inp(n);
	ffor(i,n){
		cin >> inp[i];
	}
	unordered_map<ull,int> mp;
	ffor(i,n){
		ull idx = convert(inp[i]);
		if(mp.count(idx) == 0 ){
			mp[idx]=0;
		}
		mp[idx]+=1;
	}
	for(auto it = mp.begin(); it!=mp.end();it++){
		if(it->second<=1){
			continue;
		}
		
		ans += (ull)it->se * (it->se - 1) / 2;
	}
	cout << ans;
}