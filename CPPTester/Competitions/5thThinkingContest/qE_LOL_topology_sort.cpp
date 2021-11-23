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
	unordered_map<string, int> hm;
	int n,itemCnt=0, idO, idT;
	cin >> n;
	
	vector<int> edgePointTo[2*n+1];//edge[i] = j -> i then j in topology
	vector<int> edgePointedBy(2*n+1,0);
	vector<string> names;
	ffor(i,n){
		string name;
		cin >> name; 
		if(hm.find(name) == hm.end()){
			hm[name]=itemCnt++;
			names.push_back(name);
			idO = itemCnt-1;
		}
		else idO = hm.find(name)->second;
		
		string nameT;
		cin >> nameT; 
		if(hm.find(nameT) == hm.end()){
			hm[nameT]=itemCnt++;
			names.push_back(nameT);
			idT = itemCnt-1;
		}
		else idT = hm.find(nameT)->second;
		
		if(idO!=idT){
			edgePointTo[idO].push_back(idT);
			edgePointedBy[idT]++;
		}
	}
	vector<int> topoLevel[2*n];
	for(int i=0;i<itemCnt;i++){
		if(edgePointedBy[i]==0){
			topoLevel[0].push_back(i);
		}
	}
	queue<pair<int,int>> q;
	int vstd = 0; //itemCnt
	for(auto t:topoLevel[0]){
		q.push({t,0});
		vstd++;
	}
	while(!q.empty()){
		auto p = q.front();
		int idx = p.first;
		int lvl = p.second;
		//cout << names[idx] << " " <<lvl << endl;
		q.pop();
		
		for(auto k : edgePointTo[idx]){
			if((--edgePointedBy[k])==0){
				vstd++;
				topoLevel[lvl+1].push_back(k);
				q.push({k,lvl+1});
			}
		}
		
	}
	if(vstd!=itemCnt){
		cout<<-1<<endl;
		return 0;
	}
	
	for(vector<int> k : topoLevel){
		if(k.size()==0)continue;
		vector<string> temp;
		for(int p:k){
			temp.push_back(names[p]);
		}
		sort(temp.begin(),temp.end());
		for(string p:temp){
			cout<<p<<endl;
		}
	}
	return 0;
}