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
#define N 5000
#define M 10000
using namespace std;

int numM[4] = {1,3,7,15}; //옷걸이 개수
int numC[4] = {1,2,4,0}; // 옷 개수
int dp[N+1][M+1]; // dp[n][m] = n 개의 옷걸이 위치와 m개의 옷걸이가 남았을때 최대 

void doCalc(int n, int m){//n개의 옷걸이 위치와 m개의 옷걸이가 남음
	if(m==0 && n>=0){
		//dp[n][m]=0;
		return;
	}else if(n==0){
		//dp[n][m]=-1e6;
		return;
	}else if(m<=n){
		dp[n][m]=m;
		return;
	}
	int & ret = dp[n][m];
	if(ret!=-1)return;
	ret = -1e6;
	for(int i=0;i<4;i++){
		if(m<numM[i])break;
		doCalc(n-1,m-numM[i]);
		ret = max(numC[i]+dp[n-1][m-numM[i]],ret);
	}
	return;
}

int main(){
	fastio;
	int n, m;
	cin >> n >> m;
    
    
	for(int i=0;i<=m;i++){
		dp[0][i]=-1e6;
	}
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=-1;
		}
	}
	doCalc(n,m);
	int t = dp[n][m];
	if(t<0){
		cout<<-1<<endl;
		
	}else{
		cout<<t<<endl;	
	}
	//printf("%d",mx);
	return 0;
}