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
	//each sccGroup's inEdge # (0==0, 1== >0)
	vector<bool> inEdge;
	//stack for visited nodes
	stack<int> st;
	int n,e,sccCounter,vCounter;
	SCC(int n, int e){
		this->n = n;
		this->e = e;
		edge=vector<vector<int>>(n+1);
		sccId=vector<int>(n+1,-1);
		vstd=vector<int>(n+1,-1);
		inEdge=vector<bool>(n+1,0);
	}
	void addEdge(int a, int b){
		edge[a].push_back(b);
	}
	//In a subtree with x as root, 
	//return min discovered in reverse edge or cross edge
	//(ignore cross edge ardy in SCC)
	void scc(int x){
		int ret = vstd[x] = vCounter++;
		//put x in stack. 
		//Children of x are put in stack after x
		for(auto a:edge[x]){
			//cout << x << "'s edge= " << a<<endl;
			if(vstd[a]==-1)scc(a);
		}
		st.push(x);
	}
	void traverse(int x){
		vstd[x]=1;
		for(auto a:edge[x]){
			if(vstd[a]==-1)traverse(a);
		}
	}
};

int main(){
	fastio;
	int t,n,m,a,b;
	cin >> t;
	
	while(t--){
		int ans=0;
		cin >> n >> m;
		SCC * root = new SCC(n,m);
		ffor(i,m){
			cin >> a >> b;
			root->edge[a].push_back(b);
		}
		
		forr(i,n){
			if(root->vstd[i] == -1){
				root->scc(i);
			}
		}
		root->vstd.assign(n+1,-1);
		while(!root->st.empty()){
			int p = root->st.top();
			//cout << p << endl;
			root->st.pop();
			if(root->vstd[p]==-1){
				ans++;
				root->traverse(p);
			}
		}
		cout << ans <<endl;
	}
}
