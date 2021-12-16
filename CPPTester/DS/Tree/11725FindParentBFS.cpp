#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define d double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define MAX 100001
using namespace std;



int main(){
	vector<int> nd[MAX];
	int pr[MAX]={0};
	int n,x,y;
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> x >> y;
		nd[x].push_back(y);
		nd[y].push_back(x);
	}
	
	queue<pii> bfs;
	bfs.push({1,1});
	while(!bfs.empty()){
		pii fr = bfs.front();
		int prn = fr.first;
		int cur = fr.second;
		bfs.pop();
		for(int i=0;i<nd[cur].size();i++){
			int nxt=nd[cur][i];
			if(pr[nxt]==0){
				pr[nxt]=cur;
				bfs.push({cur,nxt});
			}
		}
	}
	
	for(int i=2;i<=n;i++)cout << pr[i]<<endl;
	
}