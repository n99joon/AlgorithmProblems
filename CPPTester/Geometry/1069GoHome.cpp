#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 6001
#define fi first
#define se second
#define eb 0.000000001
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};

int main(){
	fastio;
	db x,y,d,t;
	cin >> x >> y >> d >> t;
	db dist = sqrt(pow(x,2)+pow(y,2));
	int mx = (int)(dist/d);
	if((db)d/t<=1){cout<<fixed <<setprecision(13)<<dist;}
	else if(mx==0){cout<<fixed<<setprecision(13)<<min(dist,min(d-dist+t,2*t));}
	else{
		cout <<fixed<<setprecision(13)<< min(dist,min(dist - mx*d + mx*t, (mx+1)*t));
	}
}