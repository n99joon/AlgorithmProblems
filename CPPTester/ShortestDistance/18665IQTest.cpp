#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;
vector<ll> visited = {0,1,2};
queue<pair<ll,ll>> st;
void recurse(ll k){
	if(find(visited.begin(),visited.end(),k)!=visited.end()){
		return;
	}else{
		ll t = (ll)(sqrt(k)); //t=i^2 - j;
		ll i = k==t*t?t:t+1;
		ll j = i*i-k;
		
		if(find(visited.begin(),visited.end(),i)==visited.end()){
			recurse(i);
			visited.push_back(i);
		}
			
		if(find(visited.begin(),visited.end(),j)==visited.end()){
			recurse(j);
			visited.push_back(j);
		}
							
		cout << i << " " << j << endl;
		visited.push_back(k);
		
	}	
}


int main() {
	fastio;
	ll x;
	cin >> x;
	
	if(x==0)cout << "1 1";
	else if(x==1)cout << "1 0";
	else if (x==2)cout << "2 2";
	else recurse(x);
		
	
		
}