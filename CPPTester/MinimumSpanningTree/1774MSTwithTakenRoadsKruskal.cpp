#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 1001
using namespace std;

int uf[MAX];
int Size[MAX];
pii coor[MAX];
bool connected[MAX][MAX];

double findD(ll x, ll y, ll i, ll j){
	return sqrt((x-i)*(x-i)+(y-j)*(y-j));
}

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
	int n,m,x,y;
	cin >> n >> m;
	forr(i,n){
		cin >> coor[i].first >> coor[i].second;
	}
	iota(uf+1,uf+n+1,1);
	forr(i,m){
		cin >> x >> y;
		connected[x][y]=1;
		connected[y][x]=1;
		makeUF(x,y);
	}
	priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,greater<>> pq;
	forr(i,n){
		for(int j=i+1;j<=n;j++){
			if(connected[i][j])continue;
			pq.push({findD(coor[i].first,coor[i].second,coor[j].first,coor[j].second),i,j});
			connected[j][i]=1;
		}
	}
	double d,ans=0;
	while(!pq.empty()){
		tie(d,x,y)=pq.top();
		pq.pop();
		int xk = find(x);
		int yk = find(y);
		if(xk==yk)continue;
		ans+=d;
		uf[yk]=xk;
	}
	cout << fixed << setprecision(2) << ans;
}