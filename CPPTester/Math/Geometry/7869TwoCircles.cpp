#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 6001
#define THR 3000
#define fi first
#define se second
#define eb 0.000000001
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};


db dist(db xx1, db yy1, db xx2, db yy2){
	return sqrt(pow(xx1-xx2,2)+pow(yy1-yy2,2));
}
int main(){
	fastio;
	db x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1 >> x2>> y2>> r2;
	db dis = dist(x1,y1,x2,y2);
	if(dis>=r1+r2){cout<<"0.000";return 0;}
	if(dis+min(r1,r2)<=max(r1,r2)){cout<<fixed<<setprecision(3)<<acos(-1)*pow(min(r1,r2),2);return 0;}
	db thetaO = acos((pow(r1,2)+pow(dis,2)-pow(r2,2))/2/r1/dis);
	db thetaT = acos((pow(r2,2)+pow(dis,2)-pow(r1,2))/2/r2/dis);
	db area = thetaO*r1*r1+thetaT*r2*r2-r1*cos(thetaO)*r1*sin(thetaO)-r2*cos(thetaT)*r2*sin(thetaT);
	cout << fixed << setprecision(3) << area;
}