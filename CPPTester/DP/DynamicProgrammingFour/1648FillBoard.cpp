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

int n,m;

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
int solv(int ni, int mi, int bm){
	int & ret = dp[ni][mi][bm];
	//cout << "N: " << ni << " M: " <<mi << " BM: " <<bm<<endl;
	if(ret!=-1)return ret;
	if(ni==n){
		if(mi==0 && bm==0)return ret = 1;
		return ret = 0;
	}
	ret = 0;
	//if current spot is filled ardy
	pii nd = nxtD(ni,mi);
	if(bm&1)return ret = solv(nd.fi,nd.se,bm>>1);
	pii nr=nxtR(ni,mi);
	if(!(bm>>1 & 1) && mi!=m-1) {
		ret+=solv(nr.fi,nr.se,bm>>2)%mod;
	}
	ret+=solv(nd.fi,nd.se,(bm>>1)|1<<m-1)%mod;
	return ret%=mod;
}

int main(){
	fastio;
	cin >> n >> m;
	if(n*m%2==1){
		cout << 0;
		return 0;
	}
	memset(dp,-1,sizeof dp);
	solv(0,0,0);
	cout << dp[0][0][0];
}