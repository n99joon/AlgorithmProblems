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
vector<string> entry[11];

bool compare(string a, string b){
	return a.length()==b.length()?a<b:a.length()<b.length();
}
int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	int x;
	string name;
	cin >> x >> name;
	while(x!=0 || name!="0"){
		if(entry[x].size()<m){
			entry[x].push_back(name);
		}
		cin >>x>>name;
	}
	forr(i,n){
		sort(entry[i].begin(),entry[i].end(),compare);
	}
	forr(i,n){
		if(i%2==1){
			for(string k : entry[i])cout<<i << " " << k << endl;
		}
	}
	forr(i,n){
		if(i%2==0){
			for(string k : entry[i])cout<<i << " " << k << endl;
		}
	}
}