#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 201
using namespace std;

int uf[MAX];
int find(int x){
	return x == uf[x]?x:uf[x]=find(uf[x]);
}
void makeUF(int x, int y){
	x=find(x);
	y=find(y);
	uf[y]=x;
}

int main(){
	fastio;
	int n,m,t,prv;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		uf[i]=i;
	}
	forr(i,n){
		forr(j,n){
			cin >> t;
			if(t)makeUF(i,j);
		}
	}
	ffor(j,m){
		prv=t;
		cin >> t;
		if(j!=0){
			if(find(prv)!=find(t)){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	cout << "YES" << endl;
}