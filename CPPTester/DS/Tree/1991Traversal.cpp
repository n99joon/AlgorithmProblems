#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define DOT -19
using namespace std;
pii nodes[26];

void pre(int nd){
	int fr = nodes[nd].first;
	int sc = nodes[nd].second;
	cout << (char)(nd+'A');
	if(fr!=DOT)pre(fr);
	if(sc!=DOT)pre(sc);
}

void in(int nd){
	int fr = nodes[nd].first;
	int sc = nodes[nd].second;
	if(fr!=DOT)in(fr);
	cout << (char)(nd+'A');
	if(sc!=DOT)in(sc);
}

void post(int nd){
	int fr = nodes[nd].first;
	int sc = nodes[nd].second;
	if(fr!=DOT)post(fr);
	if(sc!=DOT)post(sc);
	cout << (char)(nd+'A');
}

int main(){
	int n;
	char l, r, k;
	cin >> n;
	ffor(i,n){
		cin >> k >> l >> r;
		nodes[k-'A']=make_pair(l-'A',r-'A');
	}
	pre(0);
	cout << endl;
	in(0);
	cout << endl;
	post(0);
}