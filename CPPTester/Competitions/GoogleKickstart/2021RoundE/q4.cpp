#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;


int main() {
	fastio;
	int tc;
	cin >> tc;
	for(int i=1;i<=tc;i++){
		ll k;
		cin >> k;
		double ans=0;
		for(int j=1;j<=k;j++){
			ans += (double)1/j;
		}
		//cout << fixed << setprecision(6) << (0.5772156649f + log(k)) << endl;
		cout << "Case #" << i << ": " << fixed << setprecision(6) << ans << endl;
	}
}
