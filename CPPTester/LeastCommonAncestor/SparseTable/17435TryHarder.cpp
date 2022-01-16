#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100000000ULL
#define fi first
#define se second
#define eb 0.000000001
#define mod 1000000003
using namespace std;
//vector<int> edges;
int spt[200001][33];
vector<vector<int>> rev;
vector<int> dist;

int fd(int m, int x){
	//cout << "Here: " << m << " " <<x<<endl;
	int i = 0;
	while(m>>i >0){
		if(m>>i & 1){
			x=spt[x][i];
		}
		i++;
	}
	return x;
}

void calcDist(int idx, int cnt){
	for(auto k : rev[idx]){
		if(dist[k]==2e9){
			dist[k]=cnt+1;
			calcDist(k,cnt+1);
		}
	}
}
int main(){
	fastio;
	int n,q,inp,a,b,c;
	cin >> n;
	rev.resize(n+1);
	forr(i,n){
		cin >> inp;
		spt[i][0]=inp;
		if(i!=1)rev[inp].push_back(i);
	}
	int f = spt[1][0];
	//spt[1][0]=0;

	//sparse table setup
	forr(j,32){
		for(int i=1;i<=n;i++){
			spt[i][j]=spt[spt[i][j-1]][j-1];
		}
	}
	dist.resize(n+1,2e9);
	calcDist(1,0);
	//query input
	cin >> q;
	ffor(i,q){
	
		cin >> b >> c;
		//cout << "distc : " <<dist[c] <<endl;
		cout<<fd(b,c)<<endl;
		
	}	
	
}
	
