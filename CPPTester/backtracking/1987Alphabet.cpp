#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define pii pair<int,int>
using namespace std;
bool vstd[26];
char dp[20][20];
int xm[4]={1,0,-1,0};
int ym[4]={0,1,0,-1};
int ans = 0;
int x,y;
void dfs(int xx, int yy, int cntr){
	ans = max(ans,cntr);
	for(int i=0;i<4;i++){
		int nx = xx+xm[i];
		int ny = yy+ym[i];
		if(nx>=0 && nx<x && ny>=0 && ny<y){
			if(!vstd[dp[ny][nx]-'A']){
				vstd[dp[ny][nx]-'A']=1;
				dfs(nx,ny,cntr+1);
				vstd[dp[ny][nx]-'A']=0;
			}
		}
	}
}

int main(){
	cin >> y >> x;
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			cin >> dp[i][j]; 
		}
	}
	
	vstd[dp[0][0]-'A']=1;
	dfs(0,0,1);
	
	cout << ans;
}