#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;


int main() {
	fastio;
	int t;
	int n,k;
	cin >> t;
	while(t--){
		char dp[10000];
		int prev[10000];
		for(int i=0;i<10000;i++){
			dp[i]=' ';
		}
		cin >> n >> k;
		queue<int> bfs;
		bfs.push(n);
		int flag=0;
		dp[n]='X';
		prev[n]=-1;
		while(!bfs.empty()){
			int fr = bfs.front();
			bfs.pop();
			if(flag && fr==n) continue;
			//cout << fr << ":" << dp[fr] << " ";
			int d = (2*fr)%10000;
			if(dp[d]==' ' && fr!=0){
				dp[d]='D';
				prev[d]=fr;
				if(d==k)break;
				bfs.push(d);
			}
			int s = (fr==0?9999:fr-1);
			if(dp[s]==' '){
				dp[s]='S';
				prev[s]=fr;
				if(s==k)break;
				bfs.push(s);
			}
			
			string nu = to_string(fr);
			string num = "";
			for(int i=0;i<4-nu.length();i++){
				num+="0";
			}
			num+=nu;
			string ls="",rs="";
			for(int i=0;i<4;i++){
				if(i==0)rs+=num[3];
				else rs+=num[i-1];
				if(i==3)ls+=num[0];
				else ls+=num[i+1];
			}
			int l=stoi(ls);
			if(dp[l]==' '){
				dp[l]='L';
				prev[l]=fr;
				if(l==k)break;
				bfs.push(l);
			}
			int r=stoi(rs);
			if(dp[r]==' '){
				dp[r]='R';
				prev[r]=fr;
				if(r==k)break;
				bfs.push(r);
			}
			flag=1;
		}
		string ans="";
		while(k!=n){
			ans+=dp[k];
			k=prev[k];
		}
		reverse(ans.begin(),ans.end());
		cout << ans << endl;
	}
}