#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int xmov[4]={1,0,-1,0};
int ymov[4]={0,1,0,-1};
int x,y;

struct path{
	int i,j,broke,d; //x, y, if broke = 1, not yet = 0, d = distance so far
};

bool isVal(int i,int j){
	return (i>=0 && i<x && j>=0 && j<y);
}
int main() {
	fastio;
	
	cin >> y >> x;
	int mtrx[y][x];
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			char k;
			cin >> k;
			mtrx[i][j]=k-'0';
		}
	}
	int visited[y][x][2];
	fill_n(&visited[0][0][0],y*x*2,0);
	queue <path>q;
	q.push({0,0,0,0});//x,y,broke,dist
	int flag=0;
	
    if(x==1 && y==1) cout << 1;
    else{
        while(!q.empty()){
		
		
		path k = q.front();
		int xp = k.i;
		int yp = k.j;
		int broke = k.broke;
		int d = k.d;
		q.pop();
		if(visited[yp][xp][broke]==1)continue;
		
		for(int i=0;i<4;i++){
			int newx = xp+xmov[i];
			int newy = yp+ymov[i];
			if(isVal(newx,newy)){
				if(newx==x-1 && newy==y-1){
					cout << d+2;
					flag =1;
					break;
				}
				else if(!mtrx[newy][newx]){// no wall
					q.push({newx,newy,broke,d+1});
					//cout << newx << " " << newy << " " << broke << " " << d+1 << endl;
				}else{//yes wall
					if(!broke){
						q.push({newx,newy,1,d+1});
						//cout << newx << " " << newy << " " << 1 << " " << d+1 << endl;
					}
				}
			}
		}
		visited[yp][xp][broke]=1;
		if(flag)break;
	}
	if(!flag)cout << -1;
    }
	
}
