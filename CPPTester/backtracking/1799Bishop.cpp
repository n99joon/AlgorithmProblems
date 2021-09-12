#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
int board[10][10]={0};
int cntr[2],cnt,cntW,cntB;
int n,f=0;
int ld[21],rd[21];//ld=x+y, rd=n-x+y-1


void calc(int x, int y, int count){
	if(y>=n){
		y=f^(++x%2);
	}
	if(count==cnt || x>=n){
		cntr[f]=max(cntr[f],count);
		return;
	}
	
	if(board[y][x] && !ld[x+y] && !rd[n-x+y-1]){
		ld[x+y]=rd[n-x+y-1]=1;
		//cout << "couted " << x << " " << y << endl;
		calc(x,y+2,count+1);
		ld[x+y]=rd[n-x+y-1]=0;
		calc(x,y+2,count);
	}	
	else{
		calc(x,y+2,count);
	}	
}

int main() {
	fastio;
	cin >> n;
	for(int y=0;y<n;y++){
		for(int x=0;x<n;x++){
			cin >> board[y][x];
			if(board[y][x] && (y+x)&1)cntW++;//odd=w 
			else if(board[y][x] && !((y+x)&1))cntB++;
		}
	}
	cnt=cntB;
	calc(0,0,0);
	f=1;
	cnt=cntW;
	calc(0,1,0);
	
	/*
	cout << cntB << endl;
	cout << cntr[0] << endl;
	cout << cntW << endl;
	cout <<cntr[1] << endl;
	*/
	cout << cntr[0]+cntr[1] <<endl;
	
}