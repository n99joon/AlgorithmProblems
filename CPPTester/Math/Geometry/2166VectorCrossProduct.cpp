#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;


int main() {
	fastio;
	int n;
	cin >> n;
	pii pts[n];
	for(int i=0;i<n;i++){
		cin >> pts[i].first >> pts[i].second;
	}
	int strx = pts[0].first;
	int stry = pts[0].second;
	
	ll ans = 0;
	for(int i=1;i<n-1;i++){
		ll fpx = pts[i].first;
		ll fpy = pts[i].second;
		ll spx = pts[i+1].first;
		ll spy = pts[i+1].second;
		
		ll vox = fpx - strx;
		ll voy = fpy - stry;
		ll vtx = spx - fpx;
		ll vty = spy - fpy;
		
		cout << vox*vty - voy*vtx << endl;
		ans += vox*vty - voy*vtx;
	}
	
	cout << fixed << setprecision(1) << abs((double)ans*0.5);
}