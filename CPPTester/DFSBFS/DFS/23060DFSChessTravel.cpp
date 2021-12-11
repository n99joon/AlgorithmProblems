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
int vstd[501][501];
vector<pii> mov={
	{1,2},
	{2,1},
	{-1,2},
	{-2,1},
	{1,-2},
	{2,-1},
	{-1,-2},
	{-2,-1}};
vector<pii> vst;
int flag = 0;
bool isVal(int r, int c, int n){
	return r<=n && r>0 && c<=n && c>0;
}
void dfs(int r, int c, int vc, int n){
	if(flag)return;
	if(vc>2*n*n){
		cout<<-1;
		flag=1;
		return;
	}
	vst.push_back({r,c});
	for(int i=0;i<8;i++){
		int nr = r+mov[i].fi;
		int nc = c+mov[i].se;
		if(isVal(nr,nc,n) && !vstd[nr][nc]){
			vstd[nr][nc]=1;
			dfs(nr,nc,vc+1,n);
			vst.push_back({r,c});
		}
	}
}

int main(){
	fastio;
	int n, r, c;
	cin >> n >> r >> c;
	if(n==2 || n==3){
		cout << -1;
		return 0;
	}
	vstd[r][c]=1;
	dfs(r,c,1,n);
	if(flag)return 0;
	cout << vst.size() << endl;
	for(auto a : vst){
		cout << a.fi << " " <<a.se << endl;
	}
}