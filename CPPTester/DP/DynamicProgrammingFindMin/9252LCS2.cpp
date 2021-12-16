#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
using namespace std;
int n;

int main() {
	fastio;
	string l,s;
	cin >> s >> l;
	
	int ll = l.length();
	int sl = s.length();
	
	vector<int> eg[sl];
	for(int i=0;i<sl;i++){
		for(int j=0;j<ll;j++){
			if(l[j]==s[i])eg[i].push_back(j);
		}
	}
	
	int dp[sl+1],temp[sl+1],ans[sl+1][ll+1];
	fill_n(&ans[0][0],(sl+1)*(ll+1),-1e9);
	fill_n(temp,sl+1,1e9);
	fill_n(dp,sl+1,1e9);
	int cnt = -1;
	for(int i=0;i<sl;i++){
		copy(temp,temp+sl+1,dp);
		for(int j=0;j<eg[i].size();j++){ //eg[i][j] = long string's index that matches with s[i]
			int dst = eg[i][j];
			auto k = lower_bound(dp,dp+sl+1,dst)-dp; // k = position of LIS that eg[i][j] can fit 
			//kth's position is changed in LIS
			if(temp[k]>dst){
				temp[k]=dst;
				ans[i][j]=k;
			}
			temp[k]=min(temp[k],dst);
			if(k>cnt){
				cnt=k;;
			}
		}
	}
	cout << cnt+1 << endl;
	
	string t="";
	for(int i=sl;i>=0;i--){
		for(int j=ll;j>=0;j--){
			if(ans[i][j]==cnt){
				t+=l[eg[i][j]];
				cnt--;
				break;
			}
		}
		if(cnt<0)break;
	}
	reverse(t.begin(),t.end());
	cout << t;
}