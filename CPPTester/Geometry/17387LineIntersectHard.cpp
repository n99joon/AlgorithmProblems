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
#define eb 0.000001
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

bool dist(int i1, int i2, int i3){
	return abs(sqrt(pow((x[i1]-x[i2]),2)+pow((y[i1]-y[i2]),2))+
			  sqrt(pow((x[i3]-x[i2]),2)+pow((y[i3]-y[i2]),2))- 
			  sqrt(pow((x[i1]-x[i3]),2)+pow((y[i1]-y[i3]),2)))<eb;
}
int main(){
	fastio;
	int flag=0;
	ffor(i,4){
		cin >> x[i] >> y[i];
	}
	int k = ccw(0,1,2)*ccw(0,1,3);
	if(k>0){
		cout << 0;
		return 0;
	}else if(k==0){
		if(dist(0,2,1) || dist(0,3,1)){
			flag=1;
		}
	}
	int p = ccw(2,3,0)*ccw(2,3,1);
	if(p>0){
		cout << 0;
		return 0;
	}else if(p==0){
		if(dist(2,0,3) || dist(2,1,3)){
			flag=1;
		}
	}
	if(p*k==0){if(flag)cout<<1;else cout<<0;}
	else cout<<1;
}