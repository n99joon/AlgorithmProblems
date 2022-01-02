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
//#define mod 1000000007LL //1e9+7
#define mod 9901
using namespace std;
int dp[15][14][1<<14];
int score[5][5]={{10,8,7,5,1},
		   {8,6,4,3,1},
		   {7,4,3,2,1},
		   {5,3,2,2,1},
		   {1,1,1,1,0}};//A=0, F=4;
int n,m;
int inp[15][14];

pii nxtR(int cn, int cm){
	pii ret;
	if(cm>=m-2)ret.fi=cn+1;
	else ret.fi=cn;
	if(cm >=m-2) ret.se=(cm+2)%m;
	else ret.se=cm+2;
	
	return ret;
}
pii nxtD(int cn, int cm){
	pii ret;
	if(cm==m-1)ret.fi=cn+1;
	else ret.fi=cn;
	if(cm==m-1) ret.se=0;
	else ret.se=cm+1;
	return ret;
}

int calc(int o,int t){
	return score[o][t];
}
int solv(int ni, int mi, int bm){
	int & ret = dp[ni][mi][bm];
	//cout << "N: " << ni << " M: " <<mi << " BM: " <<bm<<" DP: "<<dp[0][0][0]<<endl;
	if(ret!=-1)return ret;
	if(ni==n){
		if(mi==0 && bm==0)return ret = 0;
		return ret = -1e9;
	}
	ret = -1e9;
	//if current spot is filled ardy
	pii nd = nxtD(ni,mi);
	if(bm&1)return ret = solv(nd.fi,nd.se,bm>>1);
	pii nr=nxtR(ni,mi);
	//right
	if(!(bm>>1 & 1) && mi!=m-1) {
		//cout << "cur ret : " <<ret<< "  search: "<<score[inp[ni][mi]][inp[ni][mi+1]]<< " + " << nr.fi << " " <<nr.se<<endl;
		ret=max(ret,score[inp[ni][mi]][inp[ni][mi+1]]+solv(nr.fi,nr.se,bm>>2));
		//cout << "retR: " <<ret<< " ni: " <<ni<<" mi: " <<mi<<" bm: " <<bm << endl;
	}
	//move down
	ret=max(ret,score[inp[ni][mi]][inp[ni+1][mi]]+solv(nd.fi,nd.se,(bm>>1)|1<<m-1));
	//cout << "retD: " <<ret<< " ni: " <<ni<<" mi: " <<mi<<" bm: " <<bm << endl;
	//skip
	ret=max(ret,solv(nd.fi,nd.se,(bm>>1)));
	//cout << "retS: " <<ret<< " ni: " <<ni<<" mi: " <<mi<<" bm: " <<bm << endl;
	return ret;
}

int main(){
	fastio;
	cin >> n >> m;
	char c;
	memset(dp,-1,sizeof dp);
	ffor(i,n){
		ffor(j,m){
			cin >> c;
			if(c=='F')c='E';
			inp[i][j]=c-'A';
		}
	}
	ffor(i,m){
		inp[n][i]=0;
	}
	solv(0,0,0);
	cout << dp[0][0][0];
}
//MCMF solve!