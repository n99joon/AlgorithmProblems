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
using namespace std;
int n,k;
ull dp[1<<17][101];
int cost[21][21];
int ten[51];
int inpMod[15];
string inp[15];

int findMod(const string &s){
	int ret = 0;
	ffor(i,s.length()){
		ret*=10;
		ret += s[i]-'0';
		ret %= k;
	}
	return ret;
}

ull findGCD(ull a, ull b){
	if(a>b)swap(a,b);
	while(a!=0){
		ull r = b%a;
		b = a;
		a = r;
	}
	return b;
}
int main(){
	fastio;
	cin >> n;
	ffor(i,n){
		cin >>inp[i];
	}
	cin >> k;
	
	
	ten[0]=1%k;
	forr(i,50){
		ten[i]=(ten[i-1]*10)%k;
	}
	
	ffor(i,n){
		inpMod[i]=findMod(inp[i]);
	}
	
	dp[0][0]=1;
	ffor(cur, 1<<n){
		ffor(i,n){
			if((cur & 1<<i) ==0){
				int nxtS = cur | 1<<i;
				ffor(j,k){
					int nxtK = ((j*ten[inp[i].length()])%k + inpMod[i])%k;
					//cout << nxtK << endl;
					dp[nxtS][nxtK]+=dp[cur][j];
				}
			}
		}
	}
	
	ull deno = 1;
	forr(i,n){
		deno *= i;
	}
	ull numer = dp[(1<<n)-1][0];
	if(numer == 0) {cout << "0/1";return 0;}
	ull gcd = findGCD(deno,numer);

	cout << numer / gcd << "/" << deno / gcd<<endl;
	//for(auto a : ten)cout << a << " ";
}