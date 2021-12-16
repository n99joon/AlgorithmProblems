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
int tc,n;
vector<pii> inp;
ull area;
ull yes(int i, int j){
	ll x = inp[j].fi - inp[i].fi;
	ll y = inp[j].se - inp[i].se;
	//cout << i << " " << j << endl;
	//cout << x << " " <<y << endl;
	pii in1 = {inp[i].fi+y,inp[i].se-x};
	pii in2 = {inp[j].fi+y,inp[j].se-x};
	//pii in3 = {inp[i].fi-y,inp[i].se+x};
	//pii in4 = {inp[j].fi-y,inp[j].se+x};
	if(binary_search(inp.begin(),inp.end(),in1)&&binary_search(inp.begin(),inp.end(),in2)){
		return pow(x,2)+pow(y,2);
	}
	return 0;
}


int main(){
	fastio;
	cin >> tc;
	while(tc--){
		area=0;
		cin >> n;
		inp.resize(n);
		ffor(i,n){
			cin >> inp[i].fi >> inp[i].se;
		}
		sort(inp.begin(),inp.end());
		ffor(i,n){
			for(int j=i+1;j<n;j++){
				ull ans = yes(i,j);
				if(ans != 0){
					area = max(area, ans);
				}
			}
		}
		cout << area<<endl;
	}
}