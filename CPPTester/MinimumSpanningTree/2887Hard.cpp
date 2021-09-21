#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100001
using namespace std;
//2887
int n;
priority_queue<pii> xpq;
priority_queue<pii> ypq;
priority_queue<pii> zpq;
int uf[MAX], rk[MAX];

struct compare{
	bool operator()(tuple<int,int,int> &x, tuple<int,int,int> &y){
		if(get<0>(x) < get<0>(y)) return true;
		else if(get<1>(x) < get<1>(y)) return true;
		else if(get<2>(x) < get<2>(y)) return true;
		return false;
	}
};

int find(int x){
	return x == uf[x]?x:uf[x]=find(uf[x]);
}
bool makeUF(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)return false; //already connected
	if(rk[x]<rk[y])swap(x,y);
	else if(rk[x]==rk[y]) rk[x]++;
	uf[y]=x;
	return true;
}

int main(){
	fastio;
	int x,y,z;
	cin >> n;
	
	ffor(i,n){
		cin >> x >> y >> z;
		xpq.push({x,i});
		ypq.push({y,i});
		zpq.push({z,i});
	}
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;//dist, idxFr, idxTo
	
	pii frx = xpq.top();
	int nx = frx.first, xi = frx.second;
	xpq.pop();
	pii fry = ypq.top();
	int ny = fry.first, yi = fry.second;
	ypq.pop();
	pii frz = zpq.top();
	int nz = frz.first, zi = frz.second;
	zpq.pop();
	ffor(i,n-1){
		pii frxx = xpq.top();
		int nxx = frxx.first, xxi = frxx.second;
		pii fryy = ypq.top();
		int nyy = fryy.first, yyi = fryy.second;
		pii frzz = zpq.top();
		int nzz = frzz.first, zzi = frzz.second;
		xpq.pop();
		ypq.pop();
		zpq.pop();
		//cout << nz-nzz << " " <<zi << " " <<zzi <<endl;
		pq.push({nx-nxx,xi,xxi});
		pq.push({ny-nyy,yi,yyi});
		pq.push({nz-nzz,zi,zzi});
		
		nx=nxx,xi=xxi;
		ny=nyy,yi=yyi;
		nz=nzz,zi=zzi;
	}
	int vstd = 0;
	int dist, idxFr, idxTo;
	ull ans=0;
	iota(uf,uf+n,0);
	while(vstd<n-1){
		tie(dist,idxFr,idxTo)=pq.top();
		pq.pop();
		//cout << idxFr << " " << idxTo << " " <<dist <<endl;
		if(!makeUF(idxFr,idxTo))continue;
		//cout << idxFr << " " << idxTo << " " <<dist <<endl;
		ans+=dist;
		vstd++;
	}
	cout << ans;
	
}