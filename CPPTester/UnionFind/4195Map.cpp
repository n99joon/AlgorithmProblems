#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 200001
using namespace std;

int uf[MAX];
int Size[MAX];
map<string,int> m;

int insertMap(string a, int x){
	auto k = m.find(a);
	if(k==m.end()){
		m.insert({a,x});
		return x;
	}
	return k->second;
}

int find(int x){
	return x == uf[x]?x:uf[x]=find(uf[x]);
}

int main(){
	fastio;
	int tc,idxA,idxB,x,y;
	
	string a ,b;
	cin >> tc;
	while(tc--){
		int n,cnt=1;
		cin >> n;
		iota(uf+1,uf+n*2+1,1);
		fill_n(Size,MAX,1);
		forr(i,n){
			cin >> a >> b;
			idxA=insertMap(a,cnt);
			if(idxA==cnt)cnt++;
			idxB= insertMap(b,cnt);
			if(idxB==cnt)cnt++;
			
			x=find(idxA);
			y=find(idxB);
			if(x!=y){
				uf[y]=x;
				Size[x]+=Size[y];
				Size[y]=Size[x];
			}
			cout << Size[x] << endl;
		}
	}
}