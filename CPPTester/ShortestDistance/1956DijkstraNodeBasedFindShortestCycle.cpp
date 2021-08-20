#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
#define MAXV 400
using namespace std;
vector<pair<int,int>>em[MAXV+1];
long dist[MAXV+1];
int v,e,cl=1e9;

void findDist(int s){

	priority_queue<pair<int, int>> PQ; //dist, destination
    PQ.push({0, s});
	
	while (!PQ.empty())
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        //if(dist[Cur]< -Cost)continue; //reduces 4 ms
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
	if(dist[s]<cl){
		cl=dist[s];
		/*
		cout << "s is " << s << endl;
		for(int i=1;i<=v;i++){
			cout << dist[i] << " ";
		}
		cout << endl;
		*/
	}
	
}
int main() {
	fastio;
	
	
	cin >> v >> e;
	for(int i=0;i<e;i++){
		int st, end, w;
		cin >> st >> end >> w;
		em[st].push_back({end,w});
	}
	for(int i=1;i<=v;i++){
		fill_n(dist,MAXV+1,(int)1e9);
		findDist(i);
	}
	if(cl==1e9)cout << -1;
	else cout << cl;
}