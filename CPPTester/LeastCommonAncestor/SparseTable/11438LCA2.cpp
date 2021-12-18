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
	vector<vector<int>> edge; 
	vector<int> depth;
	int n,mx;
	
	LCA(int n){
		this->mx = (int)log2(n)+1;
		//this -> mx = sz;
		spt = vector<vector<int>>(n+1,vector<int>(mx,0));
		edge = vector<vector<int>>(n+1,vector<int>(0));
		depth = vector<int>(n+1,-1);
		depth[1]=0;
		this->n = n;
	}
	
	void addEdge(int ch, int prt){//ch = x,prt =f(x)
		edge[prt].emplace_back(ch);
		edge[ch].emplace_back(prt);
	}
	
	void dfs(int x){
		for(int next : edge[x]){
			if(depth[next]==-1){
				spt[next][0]=x;
				depth[next]=depth[x]+1;
				dfs(next);
			}
		}
	}
	void calc(){
		forr(i,mx){
			forr(j,n){
				spt[j][i]=spt[spt[j][i-1]][i-1];
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
	int findParent(int x, int i){//return ith ancestor of x
		ffor(t,mx){
			if((1<<t)&i)x=spt[x][t];
		}
		return x;
	}
	int search(int a, int b){ // a is deeper
		int al = depth[a];
		int bl = depth[b];
		if(bl>al){
			swap(a,b);
			swap(al,bl);
		}
		
		a = findParent(a,al-bl);
		if(a==b) return a;
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
};

int main(){
	fastio;
	int n,a,b,q;
	cin >> n;
	LCA * root = new LCA(n);
	forr(i,n-1){
		cin >> a >> b;
		root->addEdge(a,b);
	}
	root->dfs(1);
	root->calc();
	
	cin >> q;
	while(q--){
		cin >> a >> b;
		cout << root->search(a,b) << endl;
	}
}
//https://kibbomi.tistory.com/201
//https://m.blog.naver.com/kks227/220820773477
//https://exponential-e.tistory.com/34