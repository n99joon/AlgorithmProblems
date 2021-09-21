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
#define eb 0.000000000001
using namespace std;

struct item{
	int v,w;
};

int n, m, w[100], v[100];
vector<int> dp; //min cost for idx val

bool comp(db a, db b){
	return a-b>eb;
}

int main(){
	cin >> n >> m;
	item inp[n];
	int bag[m];
	
	int sum = 0; //value sum
	ffor(i,n){
		cin >> inp[i].w >> inp[i].v;
		sum += inp[i].v;
	}
	dp.resize(sum+1);
	fill(dp.begin(),dp.end(),1e9);
	dp[0]=0;
	ffor(i,m){
		cin >> bag[i];
	}
	ffor(i,n){
		for(int j=sum;j>=inp[i].v;j--){
			dp[j]=min(dp[j],dp[j-inp[i].v]+inp[i].w);
		}
	}
	db maxeff=0;
	int idx = 0;
	ffor(i,m){
		for(int j=sum;j>=0;j--){
			if(dp[j]<=bag[i]){
				if(comp((db)(j)/bag[i],maxeff)){
					maxeff=(db)(j)/bag[i];
					idx=i;
				}
				//cout << idx <<endl;
				//cout << (db)(j)/bag[i] << endl;
				break;
			}
		}
	}
	cout << idx+1;
}