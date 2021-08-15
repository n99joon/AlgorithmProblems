#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define p pair<int,int> 
using namespace std;
int v,e;
void bellmanFord(vector<p> eg[],long dist[]){
	//for(int i=0;i<)
	bool l=false; //there is loop
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			if(dist[j]==1e9)continue;
			for(auto &k:eg[j]){
				long f=k.first, s=k.second;
				if(dist[f]>dist[j]+s){
					dist[f]=dist[j]+s;
					if(i==v)l=true; //there is loop
				}
			}
		}
	}
	
	if(l)cout<<-1<<endl;
	else{
		for(int i=2;i<=v;i++){
			if(dist[i]==1e9)cout << -1 << endl;
			else cout << dist[i] << endl;
		}	
	}
}
int main() {
	fastio;
	cin >> v >> e;
	int a,b,c;
	vector<p> eg[v+1]; // [start] <end, cost>
	for(int i=0;i<e;i++){
		cin >> a >> b >> c;
		eg[a].push_back({b,c});
	}
	long dist[v+1];
	fill(dist,dist+v+1,1e9);
	
	dist[1]=0;
	bellmanFord(eg,dist);
}