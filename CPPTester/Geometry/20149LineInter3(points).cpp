#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 10001
#define INF 1e9
#define fi first
#define se second
#define eb 0.000000001
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};
ll x[4],y[4];
int ccw(int i1, int i2, int i3) {
	ll ret = (x[i1] * y[i2] + x[i2] * y[i3] + x[i3] * y[i1]) -
			 (y[i1] * x[i2] + y[i2] * x[i3] + y[i3] * x[i1]);
	if (ret>0) return 1;
    if (ret<0) return -1;
	return 0;
}

bool dist(int i1, int i2, int i3){
	return abs(sqrt(pow((x[i1]-x[i2]),2)+pow((y[i1]-y[i2]),2))+
			  sqrt(pow((x[i3]-x[i2]),2)+pow((y[i3]-y[i2]),2))- 
			  sqrt(pow((x[i1]-x[i3]),2)+pow((y[i1]-y[i3]),2)))<=eb;
}

bool slope(int i1, int i2, int i3, int i4){
	return abs((db)(y[i2]-y[i1])/(x[i2]-x[i1])-(db)(y[i4]-y[i3])/(x[i4]-x[i3]))<=eb;
}
pii trend(int i1, int i2){
	ll xtr = x[i2]-x[i1];
	int xt;
	if(xtr>0)xt=1;
	else if(xtr==0)xt=0;
	else xt=-1;
	ll ytr = y[i2]-y[i1];
	int yt;
	if(ytr>0)yt=1;
	else if(ytr==0)yt=0;
	else yt=-1;
	return {xt,yt};
}

db findS(int i1, int i2){
	return (db)(y[i2]-y[i1])/(x[i2]-x[i1]);
}
int main(){
	fastio;
	int flag=0;
	ffor(i,4){
		cin >> x[i] >> y[i];
	}
	int k = ccw(0,1,2)*ccw(0,1,3);
	if(k>0){
		cout << 0;
		return 0;
	}else if(k==0){
		if(dist(0,2,1) || dist(0,3,1)){
			flag=1;
		}
	}
	int p = ccw(2,3,0)*ccw(2,3,1);
	if(p>0){
		cout << 0;
		return 0;
	}else if(p==0){
		if(dist(2,0,3) || dist(2,1,3)){
			flag=1;
		}
	}
	if(p*k==0){if(flag)cout<<1<<endl;else {cout<<0;return 0;}}
	else cout<<1<<endl;
	
	/*
	cout << dist(0,2,1) <<endl;
	cout << dist(0,3,1) <<endl;
	cout << dist(2,0,3) <<endl;
	cout << dist(2,1,3) <<endl;
	cout << x[0] << " " <<y[0] <<endl;
	cout << x[1] << " " <<y[1] <<endl;
	cout << x[2] << " " <<y[2] <<endl;
	cout << x[3] << " " <<y[3] <<endl;
	*/
	//OUTPUT
	int xr, yr;
	//All four pts in line
	if(x[0]==x[1]&&x[2]==x[3] || slope(0,1,2,3)){
		pii ineq[4];
		ineq[0]=trend(0,2);
		ineq[1]=trend(1,3);
		ineq[2]=trend(1,2);
		ineq[3]=trend(0,3);
		int ovl=-1;
		ffor(i,4){
			if(ineq[i].fi == 0 && ineq[i].se == 0){
				ovl=i;
			}
		}
		if(ovl==-1)return 0;
		int xa = ovl==0?ineq[1].fi:ineq[0].fi;
		int ya = ovl==0?ineq[1].se:ineq[1].se;
		ffor(i,4){
			if(i==ovl)continue;
			if(ineq[i].fi!=xa || ineq[i].se!=ya){
				return 0;
			}
		}
		cout << x[ovl] << " " << y[ovl];
	}
	//Three pts in a line
	else if(!p || !k){ 
		if(dist(0,2,1)){
			xr=x[2];
			yr=y[2];
		}else if(dist(0,3,1)){
			xr=x[3];
			yr=y[3];
		}else if(dist(2,0,3)){
			xr=x[0];
			yr=y[0];
		}else{
			xr=x[1];
			yr=y[1];
		}
		cout<<xr<<" "<<yr<<endl;
	}
	//Exists vertical line
	else if(x[0]==x[1]){	
		if(y[2]==y[3]){
			cout << x[0] << " " << y[2] <<endl;
		}else{
			db slp = (db)(y[3]-y[2])/(x[3]-x[2]);
			db b = y[2]-slp*x[2]; //y=slp*x + b
			cout << fixed << setprecision(10) << x[0] << " " << slp*x[0]+b <<endl;
		}
	}else if(x[2]==x[3]){	
		if(y[0]==y[1]){
			cout << x[2] << " " << y[0] <<endl;
		}else{
			db slp = (db)(y[1]-y[0])/(x[1]-x[0]);
			db b = y[0]-slp*x[0]; //y=slp*x + b
			cout << fixed << setprecision(10) << x[2] << " " << slp*x[2]+b <<endl;
		}
	}
	//other cases
	else{
		db s[2];
		s[0] = findS(0,1);
		s[1] = findS(2,3);
		db c[2];
		c[0] = y[0]-s[0]*x[0];
		c[1] = y[2]-s[1]*x[2];
		
		db xm = (c[1]-c[0])/(s[0]-s[1]);
		db ym = s[0]*xm+c[0];
		cout <<fixed << setprecision(10) << xm << " " << ym <<endl;
	}
}