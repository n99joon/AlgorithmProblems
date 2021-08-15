#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int m[1001][1001]={0,};
int vst[1001]={0,};

void dfs(int v,int s){
	cout << s << " ";
	vst[s]=1;
	for(int i=1;i<=v;i++){
		if(m[s][i] && !vst[i]){
			dfs(v,i);
		}
	}
}

void bfs(int v, int s){
	cout << s << " ";
	vst[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		q.pop();
		for(int i=1;i<=v;i++){
			if(m[s][i] && !vst[i]){
				vst[i]=1;
				cout << i << " "; 
				q.push(i);
			}
		}
	}
}
int main() {
	fastio;
	int v,e,s,fr,to,n;
	cin >> v >> e;
	
	cin >> s;
	while(e--){
		cin >> fr >> to;
		m[fr][to]=1;
		m[to][fr]=1;
	}
	
	dfs(v,s);
	cout << endl;
	fill_n(vst,1001,0);
	bfs(v,s);
}
