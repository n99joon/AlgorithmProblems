#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;


//Kruskal & Union-Find
int main(){
	int v , e, f, t, c;
	cin >> v >> e;
	pii edge[e];
	priority_queue<pll,vector<pll>,greater<>> edges;
	int uf[v+1]; //union find
	fill_n(uf,v+1,-1);
	
	for(int i=0;i<e;i++){
		cin >> f >> t >> c;
		edge[i]={f,t};
		edges.push({c,i});
	}
	
	ll ret = 0;
	int edge_sel = 0;
	while(edge_sel < v-1){
		pll fr = edges.top();
		int cost = fr.first;
		int edgeN = fr.second;
		int from = edge[edgeN].first;
		int to = edge[edgeN].second;
		edges.pop();
		
		//find union-find root
		int fromR=from;
		while(1){
			if(uf[fromR]==-1)break;
			else fromR=uf[fromR];
		}
		int toR=to;
		while(1){
			if(uf[toR]==-1)break;
			else toR=uf[toR];
		}
		
		if (fromR == toR)continue;
		else{
			uf[toR]=fromR;
			edge_sel++;
			ret+=cost;
		}
	}
	cout << ret << endl;
}