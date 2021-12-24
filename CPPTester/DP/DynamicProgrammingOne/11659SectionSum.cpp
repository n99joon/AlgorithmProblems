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
	int n,m,k,fr,to;
	cin >> n >> m ;
	vector<ull> psum(n+1,0);
	forr(i,n){
		cin >> k;
		psum[i]=psum[i-1]+k;
	}
	forr(i,m){
		cin >> fr >> to;
		cout<<psum[to]-psum[fr-1]<<endl;
	}
}