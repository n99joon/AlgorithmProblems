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

int main(){
	fastio;
	
	int n;
	ull ans = 0;
	cin >> n;
	vector<int> ys(2*n);
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
	vector<int> counts(ys.size(),0); // counts for each ys
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
		
		for(int i=ytoi[rects[rect].y1];i<ytoi[rects[rect].y2];i++){
			counts[i]+=d;
		}
		if(ev[i+1].fi!=x){
			ffor(i,ys.size()-1){
				if(counts[i]>0){
					sum+=ys[i+1]-ys[i];
				}
			}
			ans+=sum*(ev[i+1].fi-x);
		}
	}
	cout << ans <<endl;
}