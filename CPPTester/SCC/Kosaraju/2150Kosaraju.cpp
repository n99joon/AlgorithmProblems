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

//Kosaraju - SCC
//Do dfs twice (in order, in reverse order)

struct SCC{
	vector<vector<int>> edge;
	vector<vector<int>> redge;//reverse edge
	//each node's scc number
	vector<int> sccId;
	//each node's discovered order
	vector<int> vstd;
	//stack for visited nodes
	stack<int> st;
	int n,e,sccCounter,vCounter;
	SCC(int n, int e){
		this->n = n;
		this->e = e;
		edge=vector<vector<int>>(n+1);
		redge=vector<vector<int>>(n+1);
		sccId=vector<int>(n+1,-1);
		vstd=vector<int>(n+1,-1);
	}
	void addEdge(int a, int b){
		edge[a].push_back(b);
		redge[b].push_back(a);
	}
	//In a subtree with x as root, 
	//return min discovered in reverse edge or cross edge
	//(ignore cross edge ardy in SCC)
	void dfs(int x){
		vstd[x]=1;
		for(auto k:edge[x]){
			if(sccId[k]==-1 && vstd[k]==-1){
				dfs(k);
			}
		}
		st.push(x);
	}
	void dfs2(int x){
		//vstd[x]=1;
		sccId[x]=sccCounter;
		for(auto k:redge[x]){
			if(vstd[k]!=-1 && sccId[k]==-1)dfs2(k);
		}
	}
	void scc(){
		if(st.empty())return;
		int x = st.top();
		st.pop();
		if(sccId[x]!=-1){
			scc();
			return;
		}
		sccId[x]=sccCounter;
		for(auto k:redge[x]){
			if(vstd[k]!=-1 && sccId[k]==-1)dfs2(k);
		}
		sccCounter++;
	}
};
int main(){
	fastio;
	int v,e,a,b;
	cin>>v>>e;
	SCC * root = new SCC(v,e);
	ffor(i,e){
		cin >> a >> b;
		root -> addEdge(a,b);
	}
	
	forr(i,v){
		if(root->sccId[i] == -1){
			root->dfs(i);
			root->scc();
			root->vstd.assign(v+1,-1);
		}
	}
	/*
	for(auto p : root->sccId){
		cout << p << " ";
	}*/
	cout<<root->sccCounter<<endl;
	vector<int> op[root->sccCounter];
	unordered_map<int,int>ans; //<sccId, mapId>
	int sccNo=0;
	forr(i,v){
		if(ans.find(root->sccId[i])==ans.end()){
			ans.insert({root->sccId[i],sccNo++});
		}
		op[ans[root->sccId[i]]].push_back(i);
	}
	for(auto k:op){
		for(auto t:k){
			cout << t << " ";
		}
		cout << -1 << endl;
	}
}
