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
int ans[250001];
int n,m,k,s;
int inp[501][501];
pii stud[250001];
int rcvd[250001];//0=begin, else # = student given from

int xm[8]={-1,0,1,1,1,0,-1,-1};
int ym[8]={1,1,1,0,-1,-1,-1,0};

bool valid(int x, int y){
	if(x>0 && y>0 && x<=n && y<=m && inp[x][y]!=0)return true;
	return false;
}
int main(){
	fastio;
	cin >> n >> m >> k;
	int x,y;
	forr(i,k){
		cin >> x >> y;
		inp[x][y]=i;
		stud[i]={x,y};
	}
	cin >> s;
	priority_queue<pair<int,pii>>pq;//iter, # give, # get
	pq.push({0,{-s,-s}});
	stack<int> st;
	//st.push(s);
	//rcvd[s]=s;
	while(!pq.empty()){
		int iter = pq.top().fi;
		int give = -pq.top().se.fi;
		int get = -pq.top().se.se;
		pq.pop();
		if(rcvd[get]!=0)continue;
		rcvd[get]=give;
		pii getxy = stud[get];
		st.push(get);
		//cout<<"s top: " <<st.top() << endl;
		ffor(i,8){
			int nx = getxy.fi+xm[i];
			int ny = getxy.se+ym[i];
			if(valid(nx,ny)){
				
				pq.push({iter-1,{-get,-inp[nx][ny]}});
			}
		}
	}
	if(st.size()!=k){
		cout<<-1;
		return 0;
	}
	forr(i,k){
		ans[i]=1;
	}
	/*
	cout<<"rcvd: ";
	forr(i,k){
		cout<<rcvd[i]<<" ";
	}
	cout << endl;*/
	while(!st.empty()){
		int k = st.top();
		if(k==s)break;
		st.pop();
		ans[rcvd[k]]+=ans[k];
	}
	forr(i,k){
		cout<<ans[i]<<" ";
	}
}