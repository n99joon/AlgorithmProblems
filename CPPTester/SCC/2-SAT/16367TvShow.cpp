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
	//stack for topo 
	stack<int> topo;
	//vector for each node's T/F
	vector<int> tf;
	int n,sccCounter,vCounter;
	SCC(int n){
		this->n = n;
		//this->e = e;
		edge=vector<vector<int>>(2*n+1);
		sccId=vector<int>(2*n+1,-1);
		vstd=vector<int>(2*n+1,-1);
		tf=vector<int>(n+1,-1);
		sccCounter=0;
		vCounter=0;
	}
	//if var = 2, then var = 4, !var =3;
	int calcNode(int a){
		if(a<0)return -a*2-1;
		else return a*2;
	}
	bool trueFalse(int a){
		if(a%2)return 1;//odd = true
		else return 0;
	}
	void addEdge(int a, int b){
		edge[calcNode(-a)].push_back(calcNode(b));
		edge[calcNode(-b)].push_back(calcNode(a));
	}
	void addInp(int a,int b,int c,char ac,char bc,char cc){
		if(ac=='B')a=-a;
		if(bc=='B')b=-b;
		if(cc=='B')c=-c;
		addEdge(a,b);
		addEdge(b,c);
		addEdge(c,a);
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
				topo.push(t);
				sccId[t]=sccCounter;
				if(t==x)break;
			}
			sccCounter++;
		}
		return ret;
	}
	bool solv2SAT(){
		for(int i=1;i<2*n;i+=2){
			if(sccId[i]==sccId[i+1])return false;
		}
		
		while(!topo.empty()){
			int t = topo.top();
			//cout<<t<<endl;
			topo.pop();
			if(tf[(t+1)/2]!=-1)continue;
			tf[(t+1)/2]= (t%2==0?0:1);//1=true;
		}
		return true;
	}
};
int main(){
	fastio;
	int v,e,a,b,c;
	char ac,bc,cc;
	
	cin>>v>>e;
	SCC * root = new SCC(v);
	ffor(i,e){
		cin>>a>>ac>>b>>bc>>c>>cc;
		root->addInp(a,b,c,ac,bc,cc);
	}
	forr(i,2*v){
		if(root->vstd[i] == -1)root->scc(i);
	}
	if(!root->solv2SAT())cout<<-1;
	else {
		forr(i,v){
			if(root->tf[i])cout<<"R";
			else cout<<"B";
		}
	}
	cout<<endl;
}
