#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100000000ULL
#define fi first
#define se second
#define eb 0.000000001
#define mod 1000000007

using namespace std;
struct rect{
	int x1,x2,y1,y2;
};
typedef pair<int,pair<int,int>> event;

vector<pii> segT;//{sum,cnt}
vector<int> ys;
int update(int node, int nl, int nr, int findL, int findR, int d){
	//no overlap
	if(nr<findL || nl > findR){
		return segT[node].fi;
	}
	//full overlap
	if(nl>=findL && nr <= findR){
		segT[node].se+=d;
		if(segT[node].se==0){
			segT[node].fi=segT[node*2].fi+segT[node*2+1].fi;
			return segT[node].fi;
		}
		else if(segT[node].se==1){
			segT[node].fi=ys[nr+1]-ys[nl];
			return segT[node].fi;
		}
		return segT[node].fi;
	}
	
	int mid = (nl+nr)/2;
	int k = update(node*2,nl,mid,findL,findR,d)+
		update(node*2+1,mid+1,nr,findL,findR,d);
	if(segT[node].se==0)return segT[node].fi=k;
	return segT[node].fi;
}
int main(){
	fastio;
	
	int n;
	ull ans = 0;
	cin >> n;
	ys.resize(2*n);
	vector<rect> rects(n);
	vector<event> ev(2*n);//{x, {1==start&-1==end,rect no }}
	unordered_map<int,int> ytoi; //y to index
	ffor(i,n){
		cin >> rects[i].x1 >>rects[i].x2 >> rects[i].y1 >>rects[i].y2;
		ev[2*i]={rects[i].x1,{1,i}};
		ev[2*i+1]={rects[i].x2,{-1,i}};
		ys[2*i]=rects[i].y1;
		ys[2*i+1]=rects[i].y2;
	}
	sort(ys.begin(),ys.end());
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	segT.resize(ys.size()*8,{0,0});
	sort(ev.begin(),ev.end());
	ffor(i,ys.size()){
		ytoi[ys[i]]=i;
	}
	//events
	ffor(i,2*n-1){
		int x = ev[i].fi;
		int d = ev[i].se.fi;
		int rect = ev[i].se.se;
		ull sum=0;
		
		update(1, 0, ys.size()-2, ytoi[rects[rect].y1], ytoi[rects[rect].y2]-1, d);
		/*
		for(int i=ytoi[rects[rect].y1];i<ytoi[rects[rect].y2];i++){
			counts[i]+=d;
		}*/
		if(ev[i+1].fi!=x){
			sum = segT[1].fi;
			ans+=sum*(ev[i+1].fi-x);
		}
	}
	cout << ans <<endl;
}