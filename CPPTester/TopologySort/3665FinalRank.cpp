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


int main(){
	fastio;
	int t,a;
	cin >>t;
	while(t--){
		//input
		cin >> a;
		vector<int> lastyr(a);
		ffor(i,a){
			cin >> lastyr[i];
		}
		vector<int> pointTo[a+1];
		vector<int> pointedBy(a+1,0);
		ffor(i,a){
			int l = lastyr[i];
			for(int j=i+1;j<a;j++){
				pointTo[l].push_back(lastyr[j]);
				pointedBy[lastyr[j]]++;
			}
		}
		///////////////////////////////////////////
		//Change with this year
		int m;
		cin >> m;
		int fr, to;
		while(m--){
			cin >> fr >> to;
			int flag = 0;
			for(int i=0;i<pointTo[fr].size();i++){
				if(pointTo[fr][i]==to){
					pointTo[fr].erase(pointTo[fr].begin()+i);
					flag=1;
					pointedBy[to]--;
					pointTo[to].push_back(fr);
					pointedBy[fr]++;
					break;
				}
			}
			if(!flag){
				for(int i=0;i<pointTo[to].size();i++){
					if(pointTo[to][i]==fr){
						pointTo[to].erase(pointTo[to].begin()+i);
						pointedBy[fr]--;
						pointTo[fr].push_back(to);
						pointedBy[to]++;
						break;
					}
				}
			}	
		}
		/////////////////////////////////////////////
		queue<int> q;
		int vstd=0;
		for(int i=1;i<=a;i++){
			if(pointedBy[i]==0){
				q.push(i);
			}
		}
		vector<int> ans(a);
		while(!q.empty()){
			int k = q.front();
			q.pop();

			ans[vstd]=k;
			vstd++;
			//cout<<"now: " << k<<endl;
			for(int i=0;i<pointTo[k].size();i++){
				//cout<<"delete: " << pointTo[k][i] << "cur: "<<pointedBy[pointTo[k][i]]<<endl;
				if(--pointedBy[pointTo[k][i]]==0){
					q.push(pointTo[k][i]);
				}
			}
		}
		//for(auto p:ans)cout<<p<<" ";
		if(vstd!=a)cout<<"IMPOSSIBLE"<<endl;
		else{
			for(auto p:ans)cout<<p<<" ";
			cout<<endl;
		}
	}
	
	return 0;
}
