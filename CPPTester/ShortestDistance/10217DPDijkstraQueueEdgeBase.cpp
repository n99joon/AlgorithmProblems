#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
#define MAXV 100
#define MAXM 10000
using namespace std;

struct edg {
	int c,v,d;
};

vector<edg> em[MAXV+1];
//int dist[MAXV+1];
//int cost[MAXV+1];
int dp[MAXV+1][MAXM+1];
int V,e,M;
//int visited[MAXV+1];

struct compare {
	bool operator()(edg a, edg b){
		return a.c <= b.c;
	}
};


void findDist(){

	queue<edg> PQ; //cost, dest, dist
    PQ.push({0,1,0});
	
	while (!PQ.empty())
    {
        int Cur = PQ.front().v;
		int dis = PQ.front().d;
		int cos = -PQ.front().c;
        PQ.pop();
		
		if(dis > dp[Cur][cos]) continue; // reduces to 240ms
        for (int i = 0; i < em[Cur].size(); i++)
        {
            int Next = em[Cur][i].v;
            int nCost = em[Cur][i].c;
			int nDist = em[Cur][i].d;
 			
			if( cos + nCost > M || dp[Next][cos+nCost]<=dis+nDist)continue;
			else{
				for(int j=cos+nCost;j<=M;j++){
					if(dp[Next][j]<=dis+nDist)break;
					dp[Next][j]=dis+nDist;
				}
				PQ.push({-(cos+nCost),Next,dis+nDist});
			}
        }
    }
	
	if(dp[V][M]>=1e9)cout << "Poor KCM";
	else cout << dp[V][M];
	cout << endl;
	return;

}
int main() {
	fastio;
    cout.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
		//reset
		
		for(auto &k:em){
			k.clear();
		}
		
		//fill_n(dist,MAXV+1,(int)1e9);
		//fill_n(cost,MAXV+1,(int)1e9);
		//fill_n(visited,MAXV+1,0);
		fill_n(&dp[0][0],(MAXV+1)*(MAXM+1),1e9);
		
		cin >> V >> M >> e;
		for(int i=0;i<e;i++){
			int a,b,x,y;
			cin >> a >> b >> x >> y;
			//edg New = {b,x,y};
			em[a].push_back({x,b,y});
		}
		findDist();
	}
}