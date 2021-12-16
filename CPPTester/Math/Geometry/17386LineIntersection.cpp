#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 10001
#define INF 1e9
#define fi first
#define se second
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};
ll x[4],y[4];
int ccw(int i1, int i2, int i3) {
	ll ret = (x[i1] * y[i2] + x[i2] * y[i3] + x[i3] * y[i1]) -
			 (y[i1] * x[i2] + y[i2] * x[i3] + y[i3] * x[i1]);
	if (ret>0) return 1;
    if (ret<0) return -1;
	return 0;
}

int main(){
	fastio;
	
	ffor(i,4){
		cin >> x[i] >> y[i];
	}
	
	if(ccw(0,1,2)*ccw(0,1,3)>=0){
		cout << 0;
		return 0;
	}
	if(ccw(2,3,0)*ccw(2,3,1)>=0){
		cout << 0;
		return 0;
	}
	cout << 1;
}