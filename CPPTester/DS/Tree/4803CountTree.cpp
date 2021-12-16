#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define MAX 501
using namespace std;

vector<int> edge[MAX];
bool vstd[501];
bool dfs(int k, int prt){
	vstd[k]=1;
	ffor(i,edge[k].size()){
		if(edge[k][i]==prt)continue;
		if(vstd[edge[k][i]]){
			return false;
		}
		else{
			if(!dfs(edge[k][i],k))return false;
		}
	}
	return true;
}

int main(){
	int n,m,x,y,cnt,tc=0;
	cin >> n >> m;
	while(n!=0 || m!=0){
		tc++;
		for(int i=1;i<=n;i++)edge[i].clear();
		fill_n(vstd,501,0);
		cnt=0;
		
		ffor(i,m){
			cin >> x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			if(!vstd[i]){
				if(dfs(i,i))cnt++;
			}
		}

		
		cout << "Case " << tc << ": ";
		if(cnt==0)
			cout<<"No trees."<< endl;
		else if(cnt==1)
			cout <<"There is one tree." <<endl;
		else
			cout << "A forest of " << cnt << " trees."<<endl;
		cin >> n >> m;
	}
}