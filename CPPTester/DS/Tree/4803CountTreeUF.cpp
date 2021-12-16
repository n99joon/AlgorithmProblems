#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define MAX 100001
using namespace std;

int uf[501];
bool check[501];
int find(int x){
	return x == uf[x]?x:uf[x]=find(uf[x]);
}
void makeUF(int x, int y){
	x=find(x);
	y=find(y);
	x==y?check[x]=1:uf[y]=x, check[x] |=  check[y];
}

int main(){
	fastio;
	int n,m,x,y,cnt,tc=0,t;
	cin >> n >> m;
	while(n!=0 || m!=0){
		tc++;
		iota(uf+1,uf+n+1,1);
		memset(check+1,0,sizeof(bool)*n);
		ffor(i,m){
			cin >> x >> y;
			makeUF(x,y);
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(i==uf[i] && !check[i])cnt++;
		}
		cout << "Case " << tc << ": ";
		if(cnt==0)
			cout<<"No trees."<< endl;
		else if(cnt==1)
			cout <<"There is one tree." <<endl;
		else
			cout << "A forest of " << cnt << " trees."<<endl;
		cin >> n >> m;
	}
}