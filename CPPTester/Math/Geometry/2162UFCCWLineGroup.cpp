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
#define THR 3000
#define fi first
#define se second
#define eb 0.000000001
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};
int n;
int x[MAX],y[MAX];  //starting , end
vector<int> edge[THR];
int uf[THR];
int sz[THR],cnt,mx=1;

int find(int x){
	return x == uf[x]?x:uf[x]=find(uf[x]);
}

void makeUF(int x, int y){
	x=find(x);
	y=find(y);
	if(x!=y){cnt--;
	sz[x]=sz[x]+sz[y];
	sz[y]=sz[x];}
	mx=max(mx,sz[x]);
	uf[y]=x;
}

int ccw(int i1, int i2, int i3) {
	ll ret = (x[i1] * y[i2] + x[i2] * y[i3] + x[i3] * y[i1]) -
			 (y[i1] * x[i2] + y[i2] * x[i3] + y[i3] * x[i1]);
	if (ret>0) return 1;
    if (ret<0) return -1;
	return 0;
}

bool comp (int i, int j){
	return x[i]==x[j]?y[i]<y[j]:x[i]<x[j];
}

bool check (int i1, int i2, int i3, int i4){
	//all 4 pts in a line
	if(ccw(i1,i2,i3)==0  && ccw(i1,i2,i4)==0){
		if(x[i1]==x[i4] && y[i1]==y[i4])return 1;
		else if(x[i2]==x[i3] && y[i2]==y[i3])return 1;
		else return comp(i1,i4) && comp(i3,i2);
	}
	else{
		return ccw(i1,i2,i3)*ccw(i1,i2,i4)<=0 && 
			   ccw(i3,i4,i1)*ccw(i3,i4,i2)<=0;
	}
}

int main(){
	fastio;
	cin >> n;
	cnt=n;
	ffor(i,n){
		cin >> x[i] >> y[i] >> x[i+THR] >> y[i+THR];
		if(!comp(i,i+THR)){
			swap(x[i],x[i+THR]);
			swap(y[i],y[i+THR]);
		}
	}
	//ffor(i,n)cout <<x[i]<< " " <<y[i] << " " <<x[i+THR] << " " <<y[i+THR]<<endl;
		
	ffor(i,n){
		for(int j=i+1;j<n;j++){
			if(check(i,i+THR,j,j+THR)){
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	}
	
	
	iota(uf,uf+n,0);
	fill_n(sz,n,1);
	
	ffor(i,n){
		ffor(j,edge[i].size()){
			makeUF(i,edge[i][j]);
		}
	}
	cout<< cnt << endl <<mx;
	
}