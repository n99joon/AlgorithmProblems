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

struct AP{
	int v,e,count;
	vector<vector<int>> edge;
	vector<int> vstd;
	vector<bool> isCutVertex;
	set<int> ans;
	AP(int v, int e){
		this->v = v;
		this->e = e;
		vstd=vector<int>(v+1,-1);
		isCutVertex=vector<bool>(v+1,false);
		edge=vector<vector<int>>(v+1);
		count = 0;
	}
	void addEdge(int a, int b){
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int dfs(int here, bool isRoot){
		vstd[here] = count++;
		int ret = vstd[here];
		int children = 0;
		ffor(i,edge[here].size()){
			int there = edge[here][i];
			if(vstd[there]==-1){
				++children;
				int subtree = dfs(there,false);
				if(!isRoot && subtree>=vstd[here])
					isCutVertex[here]=true;
				ret = min(ret,subtree);
			}else{
				ret = min(ret, vstd[there]);
			}
		}
		if(isRoot) isCutVertex[here] = (children>=2);
		if(isCutVertex[here])ans.insert(here);
		return ret;
	}
};
int main(){
	fastio;
	int v,e,a,b;
	cin>>v>>e;
	AP * root = new AP(v,e);
	ffor(i,e){
		cin >> a >> b;
		root -> addEdge(a,b);
	}
	forr(i,v){
		if(root->vstd[i] == -1)root->dfs(i,true);
	}
	cout<<root->ans.size()<<endl;
	for(auto k : root->ans)cout<<k<<" ";
}
