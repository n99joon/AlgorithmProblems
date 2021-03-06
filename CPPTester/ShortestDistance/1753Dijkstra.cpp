#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
using namespace std;
vector<pair<int,int>>em[20001];
int dist[20001];
int v,e,s;

void findDist(){

	priority_queue<pair<int, int>> PQ; //dist, destination
    PQ.push({0, s});
	
	while (!PQ.empty())
    {
        
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        if(dist[Cur]< -Cost)continue; //reduces 4 ms
        for (int i = 0; i < em[Cur].size(); i++)
        {
            int Next = em[Cur][i].first;
            int nCost = em[Cur][i].second;
 
            if (dist[Next] > Cost + nCost)
            {
                dist[Next] = Cost + nCost;
                PQ.push({-dist[Next], Next}); //makepair to {} reduces 4ms
            }
        }
    }
	for(int i=1;i<=v;i++){
			if(dist[i]==2e9)
				cout << "INF\n";
			else
				cout << dist[i] << endl;
		}
	return;

}
int main() {
	fastio;
    cout.tie(NULL);
	fill_n(dist,20001,(int)2e9);
	cin >> v >> e >> s;
	for(int i=0;i<e;i++){
		int st, end, w;
		cin >> st >> end >> w;
		em[st].push_back({end,w});
	}
	dist[s]=0;
	findDist();
}