#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

struct p{
	int x,y,d;
};

int ar[1001][1001]={0}, cnt=0,n,m,day=0;//cnt = number of 0s, n=세로, m=가로
int movX[4]={-1,0,1,0};
int movY[4]={0,-1,0,1};
queue<p> q;

void bfs(){
	int ret=-1;
	while(!q.empty()){
		int X=q.front().x;
		int Y=q.front().y;
		int D=q.front().d;
		q.pop();
		
		for(int i=0;i<4;i++){
			if(X+movX[i]<0 || X+movX[i]>=m || Y+movY[i]<0 || Y+movY[i]>=n)continue;
			if(ar[X+movX[i]][Y+movY[i]]==0){
				ar[X+movX[i]][Y+movY[i]]=1;
				q.push(p{X+movX[i],Y+movY[i],D+1});
				if (D>day)day=D;
				cnt--;
			}
			//if(X+movX[i]==0 && Y+movY[i]==0)
			//	cout<<"\n" <<X << " " << Y << " here \n";
		}
		if(cnt==0){
			ret=day+1;
			 break;
		}
	}
	cout<<ret;
}

int main() {
	fastio;
	cin >> n >> m; //m=x, n=y
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> ar[i][j];
			if(ar[i][j]==0) cnt++;
			else if(ar[i][j]==1) q.push(p{i,j,0});
		}
	}
	//cout << "cnt is " << cnt;
	if(q.empty())cout<<-1;
	else if(cnt==0)cout<<0;
	else bfs();
}