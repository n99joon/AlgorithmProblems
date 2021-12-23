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
//타잔은 위상정렬 순으로 노드를 방문한다는 사실을 응용합니다.
//그리고 시작점으로부터 닿을 수 있는 노드들만 dfs 하는것도 포인트입니다.
//각 scc 당 총합을 구해놓고 scc가 달라질때마다 dp식으로 구하면 빠릅니다.
struct SCC{
	vector<vector<int>> edge;
	//each node's scc number
	vector<int> sccId;
	//each node's discovered order;
	vector<int> vstd;
	//each scc's total money
	vector<int> sccTotal;
	//max money if can reach this scc
	vector<int> sccMax;
	//stack for visited nodes
	stack<int> st;
	//stack for topology sort
	stack<int> topo;//scc #
	//vector for restaurants
	vector<int> rest;//1~n
	//vector for each node's money
	vector<int> nodeMoney;
	int n,sccCounter,vCounter;
	SCC(int n){
		this->n = n;
		//this->e = e;
		edge=vector<vector<int>>(n+1);
		sccId=vector<int>(n+1,-1);
		vstd=vector<int>(n+1,-1);
		nodeMoney=vector<int>(n+1);
		sccTotal=vector<int>(n+1,0);
		sccMax=vector<int>(n+1,0);
		sccCounter=0;
		vCounter=0;
	}
	void addEdge(int a, int b){
		edge[a].push_back(b);
	}
	//In a subtree with x as root, 
	//return min discovered in reverse edge or cross edge
	//(ignore cross edge ardy in SCC)
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
			}	
			//if next is not to be ignored
			else if(sccId[next] ==-1){
				ret = min(ret,vstd[next]);
			}
		}
		//decide whether to cut (x,prt[x])
		if(ret == vstd[x]){
			int t;
			while(1){
				t = st.top();
				//cout<<t<<" ";
				st.pop();
				topo.push(t);
				sccId[t]=sccCounter;
				sccTotal[sccCounter]+=nodeMoney[t];
				if(t==x)break;
			}
			sccMax[sccCounter]=sccTotal[sccCounter];
			sccCounter++;
		}
		return ret;
	}
	
	//calculate max money can get from this node
	void traverse(){
		while(!topo.empty()){
			int x = topo.top();
			//cout<<x << " ";
			topo.pop();
			for(auto a:edge[x]){	
				
				if(sccId[x]!=sccId[a]){
					sccMax[sccId[a]]=max(sccMax[sccId[a]],sccTotal[sccId[a]]+sccMax[sccId[x]]);
				}
					
				
			}
		}
	}
};

int main(){
	fastio;
	int t,n,m,a,b,s,p;
	
	cin >> n >> m;
	SCC * root = new SCC(n);
	ffor(i,m){
		cin >> a >> b;
		root->edge[a].push_back(b);
	}
	forr(i,n){
		cin >> root->nodeMoney[i];
	}
	cin >> s >> p;
	forr(i,p){
		cin >> a;
		root->rest.push_back(a);
	}
	root->scc(s);
	root->traverse();
	int mx = 0;
	ffor(i,p){
		if(root->sccId[root->rest[i]]!=-1)
		mx=max(mx,root->sccMax[root->sccId[root->rest[i]]]);
	}
	cout << mx;
}
