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

//tarjan
struct SCC{
	vector<vector<int>> edge;
	//each node's scc number
	vector<int> sccId;
	//each node's discovered order;
	vector<int> vstd;
	//stack for visited nodes
	stack<int> st;
	//# of reachable scc
	vector<int> sccReach;
	//# of inEdge
	vector<bool> inEdge;
	int n,e,sccCounter,vCounter;
	SCC(int n, int e){
		this->n = n;
		this->e = e;
		edge=vector<vector<int>>(n+1);
		sccId=vector<int>(n+1,-1);
		vstd=vector<int>(n+1,-1);
		sccReach=vector<int>(n+1,1);
		inEdge=vector<bool>(n+1,0);
		sccCounter = 0;
		vCounter = 0;
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
			if(vstd[next]==-1){
				ret=min(ret,scc(next));
				if(sccId[next]!=-1)inEdge[sccId[next]]=1;
			}	
			//if next is not to be ignored
			else if(sccId[next] ==-1){
				ret = min(ret,vstd[next]);
			}
			else{
				inEdge[sccId[next]]=1;
			}
		}
		//decide whether to cut (x,prt[x])
		if(ret == vstd[x]){
			int t;
			while(1){
				t = st.top();
				st.pop();
				sccId[t]=sccCounter;
				if(t==x)break;
			}
			if(!st.empty()){
				for(auto a: edge[st.top()]){
					if(a==t){
						inEdge[sccCounter]=1;
						break;
					}
				}
			}
			sccCounter++;
		}
		return ret;
	}
	void resetVstd(){
		vstd.assign(n+1,-1);
	}
	void dfs(int x){
		vstd[x]=1;
		for(auto a:edge[x]){
			if(vstd[a]==-1){
				dfs(a);
				if(sccId[x]!=sccId[a]){
					sccReach[sccId[x]]+=sccReach[sccId[a]];
				}
			}
		}
	}
};

int main(){
	fastio;
	int t,n,m,a,b;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		SCC * root = new SCC(n,m);
		ffor(i,m){
			cin >> a >> b;
			root->edge[a].push_back(b);
		}
		ffor(i,n){
			if(root->vstd[i]==-1){
				root->scc(i);
			}
		}
		root->resetVstd();
		ffor(i,n){
			if(!root->inEdge[root->sccId[i]] && root->vstd[i]==-1){
				root->dfs(i);
			}
		}
		int flag = 1;
		ffor(i,n){
			if(root->sccReach[root->sccId[i]]==root->sccCounter){
				cout<<i<<endl;
				flag=0;
			}
		}
		if(flag)cout<<"Confused"<<endl;
		cout<<endl;
	}
}
