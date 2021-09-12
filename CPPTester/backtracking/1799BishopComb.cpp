#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
int board[10][10]={0};
pii locB[100];//B = even
pii locW[100];
pii loc[100];
int cntB=0, cntW=0,cnt;
int ansB = 0, ansW=0, ans=0;
int n;
int xmove[4] = {1,-1,-1,1};
int ymove[4] = {1,1,-1,-1};

int ld[21],rd[21];//ld=x+y, rd=n-x+y-1

bool isVal(int x, int y){
	return x>=0 && x<n && y>=0 && y<n;
}


void calc(int idx, vector<bool> &v){
	
	if(idx==cnt){
		ans=1;
		return;
	}
	if(!v[idx]){
		calc(idx+1,v);
	}else{
		int x = loc[idx].first;
		int y = loc[idx].second;

		if(ld[x+y] || rd[n-x+y-1]){
			return;
		}	
		else{
			ld[x+y]=1;
			rd[n-x+y-1]=1;
			calc(idx+1,v);
		}	
	}	
}

int main() {
	fastio;
	cin >> n;
	int c;
	for(int y=0;y<n;y++){
		for(int x=0;x<n;x++){
			cin >> c;
			if(c && (x+y)%2==0)locB[cntB++]={x,y};
			else if(c && (x+y)%2==1)locW[cntW++]={x,y};
		}
	}
	//for(auto a:loc)cout << a.first << " " << a.second <<endl;
	//black
	cnt = cntB;
	
	for(int i=0;i<cntB;i++){
		loc[i] = locB[i];
	}
	for(int i=cntB;i>=1;i--){
		vector<bool> v(cntB-i,false);
		v.insert(v.end(),i,true);
		do{
			calc(0,v);
			if(ans!=0){
				ansB=i;
				break;
			}
			fill_n(ld,21,0);
			fill_n(rd,21,0);
		}while(next_permutation(v.begin(),v.end()));
		if(ans!=0)break;
	}
	
	
	ans=0;
	fill_n(ld,21,0);
	fill_n(rd,21,0);
	
	//white
	cnt=cntW;
	
	for(int i=0;i<cntW;i++){
		loc[i] = locW[i];
	}
	for(int i=cntW;i>=1;i--){
		vector<bool> v(cntW-i,false);
		v.insert(v.end(),i,true);
		do{
			calc(0,v);
			if(ans!=0){
				ansW=i;
				break;
			}
			fill_n(ld,21,0);
			fill_n(rd,21,0);
		}while(next_permutation(v.begin(),v.end()));
		if(ans!=0)break;
	}
	cout << ansB+ansW;
}