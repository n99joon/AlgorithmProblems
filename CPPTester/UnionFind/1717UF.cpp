#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define MAX 10000001
using namespace std;

int uf[MAX];
int find(int x){
	return x == uf[x]?x:uf[x]=find(uf[x]);
}
void makeUF(int x, int y){
	x=find(x);
	y=find(y);
	uf[y]=x;
}

int main(){
	fastio;
	int n,m,x,y,cnt,t;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		uf[i]=i;
	}
	ffor(i,m){
		cin >> t >> x >> y;
		if(!t)makeUF(x,y);	
		else{
			if(find(x)==find(y))cout << "YES" <<endl;
			else cout << "NO" << endl;
		}
	}
}