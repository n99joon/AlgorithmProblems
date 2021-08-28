#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

struct node{
	int val,cx,cy;
};

struct compare {
	bool operator()(const node& m1, const node& m2) {
		return m1.val < m2.val;
	}
};

int in[500][500];
ll dp[500][500];
priority_queue<node,vector<node>,compare> pq;
int xmov[4]={1,0,-1,0};
int ymov[4]={0,1,0,-1};
int x,y;

bool isVal(int X, int Y){
	return X>=0 && X<x && Y>=0 && Y<y;
}


int main() {
	fastio;
	cin >> y >> x;
	
	fill_n(&dp[0][0],500*500,0);
	
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			int k;
			cin >> k;
			in[i][j]=k;
			pq.push({k,j,i});
		}
	}
	dp[0][0]=1;
	
	while(!pq.empty()){
		node p = pq.top();
		ll val = p.val;
		int cx = p.cx;
		int cy = p.cy;
		pq.pop();
		
		//cout << val << " ";
		for(int i=0;i<4;i++){
			int newx=cx+xmov[i];
			int newy=cy+ymov[i];

			if(isVal(newx,newy) && in[newy][newx]>in[cy][cx]){
				dp[cy][cx]+=dp[newy][newx];
			}
		}
	}
	cout << dp[y-1][x-1];
	
}
