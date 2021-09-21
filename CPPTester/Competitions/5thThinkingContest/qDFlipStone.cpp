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
using namespace std;


int cntO=0,cntZ=0;
int num[2][8]={0}; //0 == 가로 
bool inp[8][8];
int n,srch=0;//0==0

int mini = 2e9;

void flip(int x, int y){
	if(x==0){
		ffor(i,n){
			inp[y][i]=!inp[y][i];
		}
	}else{
		ffor(i,n){
			inp[i][y]=!inp[i][y];
		}
	}
}

int cnt(){
	int o=0,z=0;
	ffor(i,n){
		ffor(j,n){
			if(inp[i][j]==1)o++;
			else z++;
		}
	}
	return min(o,z);
}

void solv(int x,int y,int nf){
	if(x==2){
		return;
	}
	int nx,ny;
	if(y==n-1){
		nx=x+1;
		ny=0;
	}else{
		nx=x;
		ny=y+1;
	}
	flip(x,y);
	int c = cnt();
	if(nf+c+1<mini){
		mini=c+nf+1;
	}
	solv(nx,ny,nf+1);
	flip(x,y);
	c = cnt();
	if(nf+c<mini){
		mini=c+nf;
	}
	solv(nx,ny,nf);
}

int main(){
	cin >> n;

	ffor(i,n){
		ffor(j,n){
			cin >> inp[i][j];
			if(inp[i][j]){num[0][i]++;num[1][j]++;cntO++;}
			else cntZ++;
		}
	}
	if(cntZ==0 || cntO==0){cout << 0; return 0;}
	solv(0,0,0);
	cout << mini;
}