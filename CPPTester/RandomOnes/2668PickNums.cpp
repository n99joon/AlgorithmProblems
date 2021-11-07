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
int n;
int inp[101];
int uf[101];
int visited[101];
vector<int> ans;

int main(){
	fastio;
	cin >> n;
	forr(i,n){
		cin >> inp[i];
	}
	int nxt;
	forr(i,n){
		int flag = 0;
		ffor(j,ans.size()){
			if(i==ans[j]){
				flag=1;
				break;
			}
		}
		if(flag)continue;
		
		visited[i]=1;
		nxt = inp[i];
		while(visited[nxt]==0){
			
			visited[nxt]=1;
			nxt=inp[nxt];
		}	
		if(nxt==i){
			ans.push_back(i);
			nxt = inp[i];
			while(nxt!=i){
				ans.push_back(nxt);
				nxt=inp[nxt];
			}
		}
		fill_n(visited,n+1,0);
	}
	cout << ans.size() <<endl;
	sort(ans.begin(),ans.end());
	for(auto a : ans)cout << a << endl;
}