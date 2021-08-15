#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
using namespace std;
vector<pair<int,int>>em[801];
int dist[801];
int v,e,s,d1s,d1f,dsn,dsf,dfn,str,f;

void findDist(int t){
	s=t;
	fill_n(dist,20001,(int)2e9);
	dist[s]=0;
	
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
	
	if(t==1){
		d1s=dist[str];
		d1f=dist[f];
	}else if(t==s){
		dsn=dist[v];
		dsf=dist[f];
	}else{
		dfn=dist[n];
	}
	return;
}
int main() {
	fastio;
    cout.tie(NULL);
	cin >> v >> e;
	for(int i=0;i<e;i++){
		int st, end, w;
		cin >> st >> end >> w;
		em[st].push_back({end,w});
	}
	cin >> str >> f;
	findDist(1);
	findDist(s);
	findDist(f);
	long d = min(d1s+dsf+dfn,d1f+dsf+dsn);
	if(d>=1e9)cout << -1;
	else cout << d;
}