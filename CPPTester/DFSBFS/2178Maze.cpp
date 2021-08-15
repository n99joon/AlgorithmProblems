#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int mx[101][101];
int v[10001];
queue<pair<int,int>> q;
int bfs(int n, int m){
	int ret=0,x,y;
	q.push(make_pair(0,0)); //front = x*m+y, back = counter
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		x=p.first/m;
		y=p.first%m;
		//printf("x=%d y=%d\n",x,y);
		v[y+x*m]=1;
		
		//좌우상하
		if(y>0 && !v[x*m+y-1] && mx[x][y-1]){
			//printf("v=%d %d\n",x*m+y-1,p.second+1);
			q.push(make_pair(x*m+y-1,p.second+1));
			v[x*m+y-1]=1;
		}
		if(y<m-1 && !v[x*m+y+1]&& mx[x][y+1]){
			if(x==n-1 && y==m-2) return p.second+1;
			//printf("v=%d %d\n",x*m+y+1,p.second+1);
			q.push(make_pair(x*m+y+1,p.second+1));
			v[x*m+y+1]=1;
		}
		if(x>0 && !v[(x-1)*m+y]&& mx[x-1][y]){
			q.push(make_pair((x-1)*m+y,p.second+1));
			//printf("v=%d %d\n",(x-1)*m+y,p.second+1);
			v[(x-1)*m+y]=1;
		}
		if(x<n-1 && !v[(x+1)*m+y]&& mx[x+1][y]){
			if(x==n-2 && y==m-1) return p.second+1;
			q.push(make_pair((x+1)*m+y,p.second+1));
			//printf("v=%d %d\n",(x+1)*m+y,p.second+1);
			v[(x+1)*m+y]=1;
		}
	}
	return -1;
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&mx[i][j]);
		}
	}
	printf("%d\n",bfs(n,m)+1);
}
