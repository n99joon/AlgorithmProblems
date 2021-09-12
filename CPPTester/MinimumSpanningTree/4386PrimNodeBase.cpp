#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define d double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
using namespace std;


int main(){
	int n;
	cin >> n;
	pair<d,d> node[n];
	d edge[n][n];
	d dist[n];
	
	ffor(i,n){
		cin >> node[i].first >> node[i].second;
	}
	ffor(i,n)
		for(int j=i+1;j<n;j++){
			d dis = sqrt((node[i].first-node[j].first)*(node[i].first-node[j].first)+(node[i].second-node[j].second)*(node[i].second-node[j].second));
			edge[i][j]=dis;
			edge[j][i]=dis;
		}
	
	bool vstd[n]={0,};
    vstd[0]=1;
	int i=0;
	d ans=0;
	fill_n(dist,n,2e9);
	ffor(t,n){
		edge[t][t]=0;
	}
	dist[0]=0;
	ffor(t,n-1){
		int minI;
		d minD=2e9;
		ffor(k,n){
			dist[k]=min(dist[k],edge[i][k]);
			//cout << k << " " << dist[k] << endl;
			if(dist[k]<minD && !vstd[k]){
				minD=dist[k];
				minI = k;
			}
		}
		
		i=minI;
		ans+=minD;
		vstd[i]=1;
	}
	cout << fixed << setprecision(2) << ans;
}