#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
using namespace std;
vector<pair<int,int>>em[20001];
int dist[20001];
unsigned char visited[20001];
int minD=0;
int mIdx,v,e,s,cnt=0;
void shortest(){
	int m=2e9,ret=-1;
	for(int i=1;i<=v;i++){
		if(dist[i]<=m && !visited[i]){
			ret=i;
			m=dist[i];
			minD=dist[i];
		}
	}
	mIdx=ret;
	visited[mIdx]=1;
}

void calcDist(){
		for(pair<int,int> j:em[mIdx]){
			if(!visited[j.first])dist[j.first]=MIN(j.second+minD,dist[j.first]);
		}
		
}


void findDist(){
	cnt++;
	if(cnt==v || mIdx==-1){
		//cout << cnt << " " << mIdx << " " << minD;
		for(int i=1;i<=v;i++){
			if(dist[i]==2e9)
				cout << "INF\n";
			else
				cout << dist[i] << endl;
		}
		return;
	}
	calcDist();
	shortest();
	findDist();
}
int main() {
	fastio;
	fill_n(dist,20001,(int)2e9);
	fill_n(visited,20001,0);
	cin >> v >> e >> s;
	for(int i=0;i<e;i++){
		int st, end, w;
		cin >> st >> end >> w;
		em[st].push_back(make_pair(end,w));
	}
	mIdx=s;
	dist[s]=0;
	visited[mIdx]=1;
	findDist();
	/*
	for(int a : visited){
		cout << a << " ";
	}*/
}