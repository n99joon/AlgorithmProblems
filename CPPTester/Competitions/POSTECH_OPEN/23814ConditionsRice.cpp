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
	ull d, n, m, k;
	cin >> d >> n>> m >> k;
	ull ans = 0;
	ull mi, mx;
	
	ull nd, md; //how many more to get one more mandu
	nd = d - n%d;
	md = d - m%d;
	if(nd > md){mi = md; mx = nd;}
	else{
		mx = md; mi = nd;
	}
	
	
	//ans += n/d;
	//ans += m/d;
	if(mi + mx <= k%d){
		cout << (k-mi-mx);
		return 0;
	}
	if(mi <= k%d){
		cout<<(k-mi);
		return 0;
	}
	
	if(mi + mx <= k%d + d && k >= d){
		cout << (k-mi-mx);
		return 0;
	}
	else {
		cout << k;
		return 0;
	}
	//cout << k;
}