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

//can't break (u,v) while traversing from root v when
//1. there is an edge to parent of v (not in scc yet)
//2. there is a crossing edge to node that is found but not in SCC yet
struct SCC{
	vector<vector<int>> edge;
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
		sccId=vector<int>(n+1,-1);
		vstd=vector<int>(n+1,-1);
	}
	void addEdge(int a, int b){
		edge[a].push_back(b);
	}
	//In a subtree with x as root, 
	//return min discovered in reverse edge or cross edge
	//(ignore cross edge ardy in SCC)
	int scc(int x){
		int ret = vstd[x] = vCounter++;
		//put x in stack. 
		//Children of x are put in stack after x
		st.push(x);
		ffor(i,edge[x].size()){
			int next = edge[x][i];
			//(x,next) = tree edge
			if(vstd[next]==-1)
				ret=min(ret,scc(next));
			//if next is not to be ignored
			else if(sccId[next] ==-1)
				ret = min(ret,vstd[next]);
		}
		//decide whether to cut (x,prt[x])
		if(ret == vstd[x]){
			while(1){
				int t = st.top();
				st.pop();
				sccId[t]=sccCounter;
				if(t==x)break;
			}
			sccCounter++;
		}
		return ret;
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
		if(root->vstd[i] == -1)root->scc(i);
	}
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
