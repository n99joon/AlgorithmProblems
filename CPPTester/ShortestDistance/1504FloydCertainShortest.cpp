//program that finds the shortest distance that passes two specific nodes.
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int v,e,s,f;
void Floyd(long dist[][801]){
	
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			for(int k=1;k<=v;k++){
				if(k==j || i==j)continue;
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
	
	long d=min(dist[1][s]+dist[s][f]+dist[f][v],dist[1][f]+dist[f][s]+dist[s][v]);
	if(d>=1e9)cout<<-1<<endl;
	else cout<<d<<endl;
}
int main() {
	fastio;
	cin >> v >> e;
	int a,b,c;
	long dist[v+1][801];
	fill(&dist[0][0],&dist[0][0]+sizeof(dist)/sizeof(dist[0][0]),(long)1e9);
	for(int i=1;i<=v;i++){
		dist[i][i]=0;
	}
	for(int i=0;i<e;i++){
		cin >> a >> b >> c;
		
		
		if(dist[a][b]>c)dist[a][b]=c;
		if(dist[b][a]>c)dist[b][a]=c;
	}
	cin >> s >> f;
	Floyd(dist);
}