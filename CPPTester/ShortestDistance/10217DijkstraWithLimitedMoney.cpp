#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
#define MAXV 100
using namespace std;

struct edge {
	int v,c,d;
};

vector<edge> em[MAXV+1];
int dist[MAXV+1];
int cost[MAXV+1]; 
int V,e,M;

void findDist(){

	queue<int> PQ; //dist, destination
    PQ.push(1);
	
	while (!PQ.empty())
    {
        int Cur = PQ.front();
		int dis = dist[Cur];
		int cos = cost[Cur];
        PQ.pop();
		
        for (int i = 0; i < em[Cur].size(); i++)
        {
            int Next = em[Cur][i].v;
            int nCost = em[Cur][i].c;
			int nDist = em[Cur][i].d;
 
            if (dist[Next] > dis+nDist && cos + nCost <= M)
            {
                dist[Next] = dis+nDist;
				cost[Next] = cos+nCost;
                PQ.push(Next); //makepair to {} reduces 4ms
            }
        }
    }
	/*
	for(int i=1;i<=V;i++){
			
				cout << dist[i] << " ";
		}
	cout << endl;
	for(int i=1;i<=V;i++){
			
				cout << cost[i] << " ";
		}
	cout << endl;
	*/	
	if(dist[V]>=1e9)cout << "Poor KCM";
	else cout << dist[V];
	cout << endl;
	return;

}
int main() {
	fastio;
    cout.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
		for(auto &k:em){
			k.clear();
		}
		fill_n(dist,MAXV+1,(int)1e9);
		fill_n(cost,MAXV+1,(int)1e9);
		cin >> V >> M >> e;
		for(int i=0;i<e;i++){
			int a,b,x,y;
			cin >> a >> b >> x >> y;
			//edge New = {b,x,y};
			em[a].push_back({b,x,y});
		}
		dist[1]=0;
		cost[1]=0;
		findDist();
	}
}