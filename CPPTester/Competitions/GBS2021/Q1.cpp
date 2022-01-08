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
	ull sx,sy,ex,ey,n,m;
	cin >> n >> m;
	cin >> sx >> sy >> ex >> ey;
	ull i = (sx+sy)%2;
	ull j = (ex+ey)%2;
	if(i==j && ((n>1 && m>1) || (sx==ex && sy==ey)))cout<<"YES";
	else cout<<"NO";
}