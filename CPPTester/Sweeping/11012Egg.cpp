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
struct human{
	int x,y;
};
//{x,{0=check, rectNo or humanNo}}
typedef pair<int,pair<int,int>> event;

vector<int> segT;//{cnt}
vector<int> ys;
vector<human> hs;//humans
vector<rect> rects;
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

int query ( int left, int right, int node, int nodeLeft, int nodeRight){
	//no overlap
	if(right < nodeLeft || left > nodeRight) return INT_MAX;
	//node is within left,right
	if(left<=nodeLeft && right>=nodeRight){
		return segT[node];
	}
	//else do recursion
	int mid (nodeLeft+nodeRight)/2;
	return min(query(left,right,node*2,nodeLeft,mid),
			  query(left,right,node*2+1,mid+1,nodeRight));
}
//to call query from outside
int query(int left, int right){
	return query(left,right,1,0,n-1);
}
int main(){
	fastio;
	int t,n,m,l,r,b,t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<event> evs;//{x,{-2=check, rectNo or humanNo}}
		hs.resize(n);
		ffor(i,n){
			cin >> hs[i].x >> hs[i].y;
			evs.push_back({hs[i].x,{0,i}});
			ys.push_back(hs[i].y);
		}
		rects.resize(m);
		ys.resize(n+2*m);
		ffor(i,m){
			cin >> rects[i].x1 >> rects[i].x2 >> rects[i].y1 >> rects[i].y2;
			evs.push_back({rects[i].x1,{-1,i}});
			evs.push_back({rects[i].x2,{1,i}});
			ys.push_back(rects[i].y1);
			ys.push_back(rects[i].y2);
		}
		
		sort(evs.begin(),evs.end());
		sort(ys.begin(),ys.end());
		ys.erase(unique(ys.begin(),ys.end()),ys.end());
		//ys compression
		unordered_map<int,int> ytoi;
		ffor(i,ys.size()){
			ytoi[i]=i;
		}
		segT.assign(8*ys.size(),0);
		//events loop
		ffor(i,evs.size()-1){
			int x = evs[i].fi;
			int ev = evs[i].se.fi; //-1 add 0 check 1 minus
			int no = evs[i].se.se;
			
			if(ev==0){
				
			}
		}
	}
}