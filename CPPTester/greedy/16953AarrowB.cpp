#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;


int main() {
	fastio;
	int a,b,c=1;
	cin >> a >> b;
	while(b>a){
		c++;
		if(b-((b/10)*10) == 1)b/=10;
		else if(b%2==0)b/=2;
		else break;
	}
	if(b==a)cout << c;
	else cout << -1;
}