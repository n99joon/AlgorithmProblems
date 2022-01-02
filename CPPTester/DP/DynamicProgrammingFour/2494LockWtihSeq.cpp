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
#define mod 1000000003
#define mx 10001
using namespace std;
int dp[mx][10];
pii outp[mx][10];//{which k it came from, how many rotations}
int cur[mx];
int targ[mx];
int cnt(int now,int tar,int d){//0=L
	int k =tar-now;
	if(d==0){
		return k>=0?k:k+10;
	}
	k=-k;
	return k>=0?k:k+10;
}
void calc(int n){
	ffor(i,10){
		int now = cur[n]+i;
		if(now>9)now-=10;
		//right
		dp[n][i]=min(dp[n][i],dp[n-1][i]+cnt(now,targ[n],1));
		if(dp[n][i]==dp[n-1][i]+cnt(now,targ[n],1)){
			outp[n][i]={i,-cnt(now,targ[n],1)};
		}
		//left
		int left = cnt(now,targ[n],0);
		int k = left + i;
		if(k>9)k-=10;
		dp[n][k]=min(dp[n][k],dp[n-1][i]+left);
		if(dp[n][k]==dp[n-1][i]+left){
			outp[n][k]={i,left};
		}
	}
}

int main(){
	fastio;
	int n;
	cin >> n;
	memset(dp,0x3f,sizeof dp);
	char c;
	ffor(i,n){
		cin >> c;
		cur[i]=c-'0';
	}
	ffor(i,n){
		cin >> c;
		targ[i]=c-'0';
	}
	//first row
	dp[0][0]=cnt(cur[0],targ[0],1);//right
	outp[0][0]={0,-dp[0][0]};
	dp[0][cnt(cur[0],targ[0],0)]=cnt(cur[0],targ[0],0);//left
	outp[0][cnt(cur[0],targ[0],0)]={0,cnt(cur[0],targ[0],0)};
	forr(i,n-1){
		calc(i);
	}
	int ans = 1e9;
	int nxt;
	ffor(i,10){
		ans=min(ans,dp[n-1][i]);
		if(ans==dp[n-1][i]){
			nxt=i;
		}
	}
	/*
	ffor(i,n){
		ffor(j,10){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << ans << endl;
	vector<int> seq(n);
	seq[n-1]=outp[n-1][nxt].se;
	nxt=outp[n-1][nxt].fi;
	for(int i=n-2;i>=0;i--){
		seq[i]=outp[i][nxt].se;
		nxt=outp[i][nxt].fi;
	}
	ffor(i,n){
		cout << i+1 << " " <<seq[i]<<endl;
	}
}