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
#define sz 19
using namespace std;
//LCA without knowing prt->child relationship
struct LCA{
	vector<vector<int>> spt; // sparse table
	vector<vector<pii>> edge; 
	//minimum dist until [j][i] 
	vector<vector<int>> min_road;
	//max dist till [j][i]
	vector<vector<int>> max_road;
	vector<int> depth;
	int n,mx;
	
	LCA(int n){
		this->mx = (int)log2(n)+1;
		//this -> mx = sz;
		spt = vector<vector<int>>(n+1,vector<int>(mx,0));
		edge = vector<vector<pii>>(n+1,vector<pii>(0));
		min_road = vector<vector<int>>(n+1,vector<int>(mx,0));
		max_road = vector<vector<int>>(n+1,vector<int>(mx,0));
		depth = vector<int>(n+1,-1);
		depth[1]=0;
		this->n = n;
	}
	
	void addEdge(int ch, int prt, int dist){//ch = x,prt =f(x)
		edge[prt].push_back({ch,dist});
		edge[ch].push_back({prt,dist});
	}
	
	void dfs(int x){
		for(auto ne : edge[x]){
			int next = ne.fi;
			int dist = ne.se;
			if(depth[next]==-1){
				spt[next][0]=x;
				min_road[next][0]=dist;
				max_road[next][0]=dist;
				depth[next]=depth[x]+1;
				dfs(next);
			}
		}
	}
	void calc(){
		forr(i,mx){
			forr(j,n){
				spt[j][i]=spt[spt[j][i-1]][i-1];
				min_road[j][i]=min(min_road[spt[j][i-1]][i-1],min_road[j][i-1]);
				max_road[j][i]=max(max_road[spt[j][i-1]][i-1],max_road[j][i-1]);
			}
		}
	}
	/*
	int getLevel(int k){
		if(spt[k][0]==0)return 0;
		int ret = 0;
		int idx = 1,mult = 1;
		while(spt[k][idx] != 0){
			idx++;
			mult*=2;
		}
		return mult+getLevel(spt[k][idx-1]);
	}*/
	tuple<int,int,int> findParent(int x, int i){//return ith ancestor of x
		int minD = 1e9;
		int maxD = 0;
		ffor(t,mx){
			if((1<<t)&i){
				minD = min(minD,min_road[x][t]);
				maxD = max(maxD,max_road[x][t]);
				x=spt[x][t];
			}
		}
		return {x,minD,maxD};
	}
	void search(int a, int b){ // a is deeper
		int al = depth[a];
		int bl = depth[b];
		if(bl>al){
			swap(a,b);
			swap(al,bl);
		}
		int minD = 1e9, maxD = 0;
		if(al-bl>0){
			tie(a,minD,maxD) = findParent(a,al-bl);
		}
		if(a==b) {
			cout<< minD << " " <<maxD <<endl;
			return;
		}
		//cout << a << " " <<b << endl;

		for(int i=mx-1;i>=0;i--){
			//if equal, then they are CA
			if(spt[a][i]==spt[b][i])continue;
			//if not equal, then they are below LCA
			minD = min(minD,min_road[a][i]);
			minD = min(minD,min_road[b][i]);
			maxD = max(maxD,max_road[a][i]);
			maxD = max(maxD,max_road[b][i]);
			a = spt[a][i];
			b = spt[b][i];
		}
		minD = min(minD, min_road[a][0]);
		minD = min(minD, min_road[b][0]);
		maxD = max(maxD, max_road[a][0]);
		maxD = max(maxD, max_road[b][0]);
		cout << minD << " " <<maxD << endl;
		return;
	}
};

int main(){
	fastio;
	int n,a,b,d,q;
	cin >> n;
	LCA * root = new LCA(n);
	forr(i,n-1){
		cin >> a >> b >> d;
		root->addEdge(a,b,d);
	}
	root->dfs(1);
	root->calc();
	
	cin >> q;
	while(q--){
		cin >> a >> b;
		root->search(a,b);
	}
}
//https://kibbomi.tistory.com/201
//https://m.blog.naver.com/kks227/220820773477
//https://exponential-e.tistory.com/34