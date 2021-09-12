#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define d double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
using namespace std;


int main(){
	int n,m,f,t;
	cin >> n >> m;
	int po[n+1];//even
	fill_n(po,n+1,-1);
	int cycle=0;
	ffor(i,m){
		cin >> f >> t;
		int fr=f,tr=t;
		while(po[fr]!=-1){
			fr=po[fr];
		}
		while(po[tr]!=-1){
			tr=po[tr];
		}
		if(fr==tr && !cycle){
			cycle=i+1;
			break;
		}
		else{
			po[tr]=fr;
		}
	}
	cout << cycle;
}