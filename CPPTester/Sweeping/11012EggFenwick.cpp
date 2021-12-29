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

vector<int> ys;
vector<human> hs;//humans
vector<rect> rects;

vector<int> fwt;
void add(int idx, int val){
		while(idx<=fwt.size()-1){
			fwt[idx]+=val;
			idx += (idx & -idx);
		}
	}
//query = x ^ (x-1) while x!=0
int query(int idx){
	int ret=0;
	while(idx!=0){
		ret+=fwt[idx];
		idx&=idx-1;
	}
	return ret;
}

int main(){
	fastio;
	int t,n,m;
	cin >> t;
	while(t--){
		int ans=0;
		cin >> n >> m;
		vector<event> evs;//{x,{-2=check, rectNo or humanNo}}
		hs.resize(n);
		ys.resize(n+2*m);
		//input of humans
		ffor(i,n){
			cin >> hs[i].x >> hs[i].y;
			evs.push_back({hs[i].x,{0,i}});
			ys.push_back(hs[i].y);
		}
		rects.resize(m);
		
		//input of rects
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
		fwt.assign(ys.size()+1,0);
		
		//ys compression
		unordered_map<int,int> ytoi;
		ffor(i,ys.size()){
			ytoi[ys[i]]=i;
		}
		//events loop
		ffor(i,evs.size()-1){
			int x = evs[i].fi;
			int ev = evs[i].se.fi; //-1 add 0 check 1 minus
			int no = evs[i].se.se;
			
			if(ev==0){
				ans += query(ytoi[hs[no].y]+1);
			}
			else{
				add(ytoi[rects[no].y1]+1,-ev);
				add(ytoi[rects[no].y2]+2,ev);
			}
			/*
			cout << x << " " <<ev << " " <<no <<" " <<ans<<endl;
			for(auto k : fwt){
				cout << k << " ";
			}
			cout <<endl;*/
		}
		cout << ans << endl;
	}
}