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
char bd[11][11];
int xm[4] = {-1,0,1,0};
int ym[4] = {0,1,0,-1};
int x, y;

int nxt(pii & pt, int idx){//br 1-b 2-r
	int d=0;
	while(bd[pt.se][pt.fi]!='#' && bd[pt.se][pt.fi]!='O'){
		pt.fi+=xm[idx];
		pt.se+=ym[idx];
		d++;
	}
	if(bd[pt.se][pt.fi]=='#'){
		pt.fi-=xm[idx];
		pt.se-=ym[idx];
		d--;
	}
	return d;
}

struct inp{
	pii b,r;
	int cnt;
};

int main(){
	fastio;
	
	//int y,x;
	cin >> y >> x;
	pii b,r,o;
	ffor(i,y){
		ffor(j,x){
			cin >> bd[i][j];
			if(bd[i][j]=='R')r={j,i};
			if(bd[i][j]=='B')b={j,i};
			if(bd[i][j]=='O')o={j,i};
		}
	}
	
	queue<inp> q;
	q.push({b,r,0});
	while(!q.empty()){
		inp cur = q.front();
		q.pop();
		if(cur.cnt==10)break;
		ffor(i,4){
			pii nb = cur.b;
			int bd=	nxt(nb,i);
			pii nr = cur.r;
			int rd=	nxt(nr,i);
			
			if(nb==nr){
				if(nb == o)continue;
				if(bd>rd){
					nb.fi-=xm[i];
					nb.se-=ym[i];
				}else{
					nr.fi-=xm[i];
					nr.se-=ym[i];
				}
			}
			//if only red is in
			if(nr == o){
				cout << cur.cnt+1;
				return 0;
			}
			if(nb==o){
				continue;
			}
			//continue
			if(nb != cur.b && nr != cur.r)q.push({nb,nr,cur.cnt+1});
		}	
	}
	
	cout << -1;
}