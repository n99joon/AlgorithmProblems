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
	//cost until [j][i] 
	vector<vector<ull>> cost;

	vector<int> depth;
	int n,mx;
	
	LCA(int n){
		this->mx = (int)log2(n)+1;
		//this -> mx = sz;
		spt = vector<vector<int>>(n+1,vector<int>(mx,0));
		edge = vector<vector<pii>>(n+1);
		cost = vector<vector<ull>>(n+1,vector<ull>(mx,0));
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
				cost[next][0]=dist;
				depth[next]=depth[x]+1;
				dfs(next);
			}
		}
	}
	void calc(){
		forr(i,mx){
			forr(j,n){
				spt[j][i]=spt[spt[j][i-1]][i-1];
				cost[j][i]=cost[spt[j][i-1]][i-1]+cost[j][i-1];
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
	//return ith ancestor of x
	int findParent(int x, int i){
		ffor(t,mx){
			if((1<<t)&i){
				x=spt[x][t];
			}
		}
		return x;
	}
	//return cost to ith ancestor of x
	ull findCost(int x, int i){
		ull ret = 0;
		ffor(t,mx){
			if((1<<t)&i){
				ret += cost[x][t];
				x=spt[x][t];
			}
		}
		return ret;
	}
	int lca (int a, int b){
		int al = depth[a];
		int bl = depth[b];
		if(bl>al){
			swap(a,b);
			swap(al,bl);
		}
		int minD = 1e9, maxD = 0;
		
		a = findParent(a,al-bl);
		
		if(a==b) {
			return a;
		}
		//cout << a << " " <<b << endl;

		for(int i=mx-1;i>=0;i--){
			//if equal, then they are CA
			if(spt[a][i]==spt[b][i])continue;
			//if not equal, then they are below LCA
			a = spt[a][i];
			b = spt[b][i];
		}
		return spt[a][0];
	}
	
	void calcCost(int u, int v){
		int ans = lca(u,v);
		ull ret = findCost(u,depth[u]-depth[ans]);
		ret+=findCost(v,depth[v]-depth[ans]);
		cout<<ret<<endl;
	}
	void calcKth(int u,int v,int k){
		k-=1;
		int ans = lca(u,v);
		int udepth = depth[u]-depth[ans];
		int vdepth = depth[v]-depth[ans];
		if(udepth>=k){
			cout<<findParent(u,k)<<endl;
		}else{
			cout<<findParent(v,vdepth-k+udepth)<<endl;
		}
	}
};

int main(){
	fastio;
	int n,a,b,d,q,k,qnum;
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
		cin >> qnum >> a >> b;
		if(qnum==1)root->calcCost(a,b);
		else {
			cin >> k;
			root->calcKth(a,b,k);
		}
	}
}
