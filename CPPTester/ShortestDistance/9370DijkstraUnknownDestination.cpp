#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
using namespace std;
vector<pair<int,int>>em[2001];
int dist[2001],distO[2001],distG[2001],distF[2001],tar[2001]={0,};
int v,e,str,des,s,d1s=1e9,d1f=1e9,dsn=1e9,dsf=1e9,dfn=1e9,g,f;

void findDist(int t){
	s=t;
	fill_n(dist,2001,(int)1e9);
	dist[s]=0;
	
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
	
	if(t==str){
		//copy array
		for(int i=1;i<=v;i++){
			distO[i]=dist[i];
		}
		//d1s=dist[g];
		//d1f=dist[f];
	}if(t==g){
		for(int i=1;i<=v;i++){
			distG[i]=dist[i];
		}
		//dsn=dist[v];
		//dsf=dist[f];
	}if(t==f){
		for(int i=1;i<=v;i++){
			distF[i]=dist[i];
		}
	}
	return;
}
int main() {
	fastio;
	int tc;
	cin >> tc;
	while(tc--){
		//reset
		fill_n(tar,2001,0);
		for (auto& v : em) {
   			v.clear();
		}
		cin >> v >> e >> des;
		cin >> str >> g >> f;
		for(int i=0;i<e;i++){
			int st, end, w;
			cin >> st >> end >> w;
			em[st].push_back({end,w});
			em[end].push_back({st,w});
		}
		for(int i=1;i<=des;i++){
			int ta;
			cin >> ta;
			tar[ta]=1;
		}
		if(e==0)cout << -1; 
		else{
			findDist(str);
			findDist(g);
			findDist(f);
		}
		for(int i=1;i<=2000;i++){
			if (tar[i]==0) continue;
			int tarV=i;
			long long shrtD=distO[tarV];
			long long d=min(distG[f]+distO[g]+distF[tarV],distO[f]+distF[g]+distG[tarV]);
			if(shrtD==d) cout << tarV << " ";
		}
		cout << endl;
		
		
	}
}