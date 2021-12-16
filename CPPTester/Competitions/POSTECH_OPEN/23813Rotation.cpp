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
	int a;
	cin >> a;
	int b = a;
	int dig=0;
	while(b>0){
		dig++;
		b/=10;
	}
	
	ull ans = 0;
	while(a>0){
		int k = a%10;
		int ten = 1;
		for(int i=0;i<dig;i++){
			ans += ten*k;
			ten*=10;
		}
		a/=10;
	}
	cout << ans;
}