#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	fastio;
	int tc, v, e, s, d;
	cin >> tc;
	while(tc--){
		cin >> v >> e;
		vector<int> edge[v+1];
		int visited[v+1]={0,};
		int ctr=0; // counts # of visited nodes
		int color[v+1]={0,};
		color[1]=1;
		int flag = 0; //0 if bipar 1 if not
        
		for(int i=0;i<e;i++){
			cin >> s >> d;
            if(s==d){
				cout <<"NO"<<endl;
				flag=1;
			}
			edge[s].push_back(d);
			edge[d].push_back(s);
		}
		if(flag)continue;
		
		stack<pair<int,int>> dfs; //src, dst
		dfs.push({1,1});
		while(!dfs.empty()){
			int src = dfs.top().first;
			int dst = dfs.top().second;
			dfs.pop();
			
			if(visited[dst])continue;
			visited[dst]=1;
			ctr++;
			
			//주변 모든 인접 노드 확인
			for(int i=0;i<edge[dst].size();i++){
				//color all edges and check colors
				int ds = edge[dst][i];
				 //색칠 안되어 있으면 색칠
				if(color[ds]==0){//not colored
					color[ds]=-color[dst];
				}
				//되어있으면 다른지 확인
				else{
					if(color[ds]==color[dst]){//same
						flag=1;
						break;
					}
				}
				
				if(!visited[edge[dst][i]]) 
					dfs.push({dst,edge[dst][i]});
			}
			if(flag) break;
			if(dfs.empty() && ctr<v){
				for(int i=1;i<=v;i++){
					if(visited[i]==0){
						dfs.push({i,i});
						color[i]=1;
						break;
					}
				}
			}
		}
		
		if(flag)cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}