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
#define maxW 45001
using namespace std;


bool dp[51][maxW/2];//dp[i][j] = whether it is possible to get a team with i people and j costs 
int main(){
	fastio;
	int n,sum=0,minD;
	cin >> n;
	
	int inp[n],last;
	ffor(i,n){
		cin >> inp[i];
		sum += inp[i];
	}
	if(n==1){
		cout << inp[0]<<endl;
		return 0;
	}
	minD = 1e9;
	last = 0;
	//0~ n-1 players calculate possible sums
	dp[0][0]=1;
	ffor(i, n){
		for(int k=n/2;k>0;k--)
		for(int j=maxW/2;j>=inp[i];j--){
			dp[k][j] |= dp[k-1][j-inp[i]];
		}
	}
	//ffor(p, sum+1) cout << p << ":"<<dp[p] << " ";
    //cout << endl;
	//cout << sum<<endl;
	//find min Difference
	ffor(i,sum+1){
		if(dp[n/2][i])minD = min(minD, abs(sum-i-i));
	}
	//cout << minD;
	int k = (sum-minD)/2;
	cout << k << " " << k + minD << endl;
}