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
#define eb 0.0000001
#define mod 1000000003
using namespace std;


int main(){
	fastio;
	ull r;
	cin >> r;
	ull y = r-1;
	ull mx = 0;
	ull mxx,mxy;
	ull x;
	x= (ull)sqrt(r*r - y*y);
	if(x*x == r*r-y*y)x--;
	/*
	while(y>r/2-1){
		x= (ull)sqrt(r*r - y*y);
		if(x*x == r*r-y*y)x--;
		ull prod = (ull)x/cos(atan2(y,x));
		//cout << prod<< endl;
		if(prod>mx){
			mx = prod;
			mxx = x;
			mxy = y;
		}
		y--;
	}
	*/
	
	cout << mxx << " " <<mxy;
}