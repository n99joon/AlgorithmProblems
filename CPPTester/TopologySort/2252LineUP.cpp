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
	int a,b;
	cin >> a >> b;
	vector<int> pointTo[a+1];
	vector<int> pointedBy(a+1,0);
	
	int fr, to;
	while(b--){
		cin >> fr >> to;
		pointTo[fr].push_back(to);
		pointedBy[to]++;
	}
	//int printed = 0;
	queue<int> q;
	for(int i=1;i<=a;i++){
		if(pointedBy[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int k = q.front();
		q.pop();
		//printed++;
		
		cout<<k<<endl;
		for(int i=0;i<pointTo[k].size();i++){
			if(--pointedBy[pointTo[k][i]]==0){
				q.push(pointTo[k][i]);
			}
		}
	}
	return 0;
}
