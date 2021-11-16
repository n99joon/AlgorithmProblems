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
using namespace std;

//dp[i] = # of picked players to take to another team/
int dp[45001];
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
	int dpTemp[45001];
	ffor(i, n){
		//copy
		ffor(k, sum+1){
			dpTemp[k]=dp[k];
		}
		//////
		ffor(j, sum+1){
			if(j==0){
				dpTemp[inp[i]]=1;
			}else if(dp[j]!=0 && dp[j]<n/2 && j+inp[i]<sum+1){
				if(dp[j+inp[i]]==0)dpTemp[j+inp[i]]=dp[j]+1;
				else dpTemp[j+inp[i]]=min(dp[j]+1,dp[j+inp[i]]);
			}
		}
		//ffor(p, sum+1) cout << p << ":"<<dpTemp[p] << " ";
		//cout << endl;
		//copy
		ffor(k, sum+1){
			dp[k]=dpTemp[k];
		}
		//////
	}
	//ffor(p, sum+1) cout << p << ":"<<dp[p] << " ";
    //cout << endl;
	//cout << sum<<endl;
	//find min Difference
	ffor(i,sum+1){
		if(dp[i]!=n/2){
			minD = min(minD, abs(sum-i-i));
		}
	}
	//cout << minD;
	int k = (sum-minD)/2;
	cout << k << " " << k + minD << endl;
}