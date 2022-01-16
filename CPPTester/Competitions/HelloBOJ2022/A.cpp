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
int pow(int x,int k){
	int ret = 1;
	while(k--){
		ret*=x;
	}
	return ret;
}
bool isVal(int k, int d){
	vector<int> yes(d,0);
	int cnt = 0;
	while(k>0){
		if(yes[k%d]==1)return false;
		if(yes[k%d]==0){
			yes[k%d]++;
			cnt++;
		}
		k/=d;
	}
	return cnt == d;
}

int main(){
	fastio;
	int n, d;
	cin >> n >> d;
	
	int strt = max(n+1,pow(d,d-1));
	int mx = pow(d,d);
	while(strt<mx){
		if(isVal(strt,d)){cout<<strt;return 0;}
		strt++;
	}
	cout << -1;
}
