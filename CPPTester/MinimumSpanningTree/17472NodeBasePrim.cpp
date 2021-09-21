#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define INF 1e9
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};
//17472
int inp[10][10];
int mapp[10][10];
int dist[6][6];
int x,y;


void bfs(int i, int j, int cnt){
	if(mapp[i][j]!=-1)return;
	mapp[i][j]=cnt;
	ffor(k,4){
		int ni = i+xmov[k];
		int nj = j+ymov[k];
		if(ni>=0 && ni<y && nj>=0 && nj<x){
			if(inp[ni][nj]==1 && mapp[ni][nj]==-1){
				bfs(ni,nj,cnt);
			}
		}
	}
}
int main(){
	fastio;
	int k,cnt=0;

	cin >> y >> x;
	
	//입력 받아오기 
	ffor(i,10)ffor(j,10)mapp[i][j]=-1;
	ffor(i,6)ffor(j,6)dist[i][j]=INF;
	ffor(i,y){
		ffor(j,x){
			cin >> k;
			inp[i][j]=k;
		}
	}
	//섬 번호 매기기
	ffor(i,y){
		ffor(j,x){
			if(inp[i][j]==1 && mapp[i][j]==-1){
				bfs(i,j,cnt++);
			}
		}
	}
	
	//섬끼리 거리 계산하기
	ffor(i,y){
		ffor(j,x){
			if(mapp[i][j]==-1)continue;
			ffor(m,4){
				int ni = i+ymov[m];
				int nj = j+xmov[m];
				int len=0;
				while(ni>=0 && ni<y && nj>=0 && nj<x){
					if(mapp[ni][nj]!=-1){
						if(len>=2 && mapp[ni][nj]!=mapp[i][j]){
							if(len<dist[mapp[ni][nj]][mapp[i][j]]){
								dist[mapp[ni][nj]][mapp[i][j]]=len;
								dist[mapp[i][j]][mapp[ni][nj]]=len;
							}
						}
						break;
					}
					ni = ni+ymov[m];
					nj = nj+xmov[m];
					len++;
				}
			}
		}
	}
	
	
	//Prim Node base로 계산하기
	int dis[6];
	ffor(i,6)dis[i]=INF;
	int idx=0,minD,minI;
	int cntr=1;
	dis[0]=0;
	bool visited[6]={0};
	int ans=0;
	

	while(cntr++<cnt){
		visited[idx]=1;
		minD=INF;
		ffor(i,6){
			if(visited[i])continue;
			dis[i]=min(dis[i],dist[idx][i]);
			if(dis[i]<minD){
				minI = i;
				minD = dis[i];
			}
		}
		idx=minI;
		ans+=minD;
		if(minD==INF){
			cout << -1;
			return 0;
		}
	}
	
	cout << ans;
}