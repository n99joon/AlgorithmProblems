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
using namespace std;

#define mx 802
//Ford-Fulkerson
int n,m;
int mf = 0;
ll sum = 0;

struct edge{
	int e, cost, cap,cur;
};
//edges
vector<vector<edge>> g; //edges[0]= source edges[-1] = sink
vector<vector<edge>> gf;

int c[mx][mx];

int cap[mx][mx],flow[mx][mx];

//Dijkstra until each node
//priority_queue<pair<ll,int>> PQ; //dist, destination

vector<int> A;
vector<int> camefrom;
vector<ll> dist;
void solv(){
	int updated=1;
	int lastNode=0;
	//while there exists an augmentation path
	while(updated){
		queue<int> q;
		q.push(0);
		
		A.assign(mx,0);
		//A.push_back(0);
		camefrom.assign(mx,0);
		dist.assign(mx,1e9);
		dist[0]=0;
		//cout << "dist[802] " << dist[802] << endl;
		updated=0;
		//dfs
		while(!PQ.empty()){
			int cur = PQ.top().se;
			ll cost = -PQ.top().fi;
			// cout << "cur node: " << cur << " cost: " << cost <<endl;
			PQ.pop();
			A[cur]=0;
			//if(A[cur]==1)continue;

			lastNode = cur;
			//update the values and put into PQ
			ffor(i, mx){
				
				if(flow[cur][i]<cap[cur][i]){
					// cout << "flow from " << cur << "to" << i << ": " <<flow[cur][i]<<endl;
					// cout << "cap: " << cap[cur][i] <<endl;
					// cout << "dist to " << i << ": " << dist[i] <<endl;
					// cout << "new dist :" << c[cur][i]+cost << endl;
					if(dist[i]>c[cur][i]+cost){
						//cout << "updated" << endl;
						dist[i]=c[cur][i]+cost;
						camefrom[i]=cur;
						if(i==mx-1){updated=1;}//have a flow
						if(A[i]==0){PQ.push({-dist[i],i});A[i]=1;}
					}
				}
			}
		}
		if(updated){
			//cout <<"updating"<<endl;
			mf++;
			//cout << dist[mx-1]<<endl;
			sum+=dist[mx-1];
			int k = mx-1;
			while(k!=0){
				int fr = camefrom[k];
				flow[fr][k]=1;
				flow[k][fr]=0;
				k = fr;
			}
		}
	}

}
int main(){
	fastio;
    

	cin >> n >> m;
	g.resize(n+m+2);
	gf.resize(n+m+2);
	// sd.assign(n+m+2,2e9);
    // sd[0]=0;
	ffor(i,mx)ffor(j,mx)c[i][j]=2e9;
    forr(i, n){
		int k;
		cin >> k;
		ffor(j,k){
			int a,b;
			cin >> a >> b; //a = m , b = cost
			//g[i].push_back({a+n,b,1,0});	
			//g[a+n].push_back({i,b,1,1});
			c[i][a+n]=b;
			c[a+n][i]=-b;
			cap[i][a+n]=1;
			cap[a+n][i]=1;//reverse
			flow[a+n][i]=1;//reverse
		}
		ffor(j,n){
			cap[0][j+1]=1;
			cap[j+1][0]=1;
			c[0][j+1]=0;
		}
		forr(j,m){
			cap[n+j][mx-1]=1;
			cap[mx-1][n+j]=1;
			c[n+j][mx-1]=0;
		}
	}
	solv();
	//cout << n << " " << m << endl;
	cout << mf << endl << sum;
}