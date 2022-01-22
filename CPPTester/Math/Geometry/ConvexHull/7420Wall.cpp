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
const double PI =3.1415926535;

using namespace std;


struct vector2{
	double x,y;
	//상대적 위치 from pivot
	double p,q; //p = x - pv.x , q = y - pv.y
	//prevent double from replacing vector using explicit in constructor
	//explicit vector2{int x_ = 0, int y_ = 0} : x(x_),y(y_){}
	vector2(double xi =0, double yi =0):x(xi),y(yi),p(0),q(0){};
	//compare two vectors
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	
	bool operator < (const vector2& rhs) const{
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	
	//vector's + & - 
	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2& rhs) const{
		return vector2(x - rhs.x, y - rhs.y);
	}
	//multiplication
	vector2 operator * (double rhs) const{
		return vector2(x * rhs, y * rhs);
	}
	//length of a vector2
	double norm() const {
		return hypot(x,y);
	}
	//return unit vector with same direction
	//exclude input of 0 vector
	vector2 normalize() const {
		return vector2(x / (hypot(x,y)), y / (hypot(x,y)));
	}
	
	//dot & cross product
	double dot(const vector2& rhs) const{
		return x * rhs.x + y * rhs.y;
	}
	double cross(const vector2& rhs) const{
		return x * rhs.y - rhs.x * y;
	}
	double crossP(const vector2& rhs) const{
		return p * rhs.q - rhs.p * q;
	}
	//projection of this vector onto rhs
	vector2 project(const vector2& rhs) const{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
	double polar() const { return atan2(y,x);}
};
//원점 기준 , based in origin
double ccw(vector2 a, vector2 b){
	return a.cross(b);
}
double ccwP(vector2 a, vector2 b){
	return a.crossP(b);
}
//점 p 기준, based in point p
double ccw(vector2 p, vector2 a, vector2 b){
	return ccw(a-p, b-p);
}
bool comp(const vector2 & a, const vector2 & b){
	double cw= ccwP(a,b);
	if(cw!=0)return cw>0;
	
	if(a.x!=b.x){
		return b.x > a.x;
	}
	return b.y > a.y;
}

void circum(const vector<vector2> & p, const int & l){
	int n = p.size();
	double dist = 0;
	//toNext[i] = p[i] 에서 다음점까지의 방향을 나타내는 벡터
	vector<vector2> toNext(n);
	ffor(i,n){
		toNext[i] = (p[(i+1)%n]-p[i]);
		dist += toNext[i].norm();
		//cout << "dist: " <<dist << endl;
	}
	/*
	ffor(i,n){
		double ang = asin((toNext[i] * (-1)).cross(toNext[(i+1)%n]) / toNext[i].norm() / toNext[(i+1)%n].norm());
		//cout << "ang: " << ang*(180/PI) <<" ";
		vector2 ninety = vector2(toNext[i].y, -toNext[i].x);
		if(ccw(ninety, toNext[(i+1)%n])>0)ang = PI - ang;
		//cout <<ang*(180/PI) <<endl;
		double add = (double)l  * ang;
		//cout << add <<endl;
		dist += add;
	}*/
	dist += 2*PI*l;
	cout << (ll)(dist + 0.5)<<endl;
	
}
	
int main(){
	fastio;
	int n,l,x,y;
	cin >> n>>l;
	
	vector<vector2> pts(n);
	ffor(i,n){
		cin >> x >> y;
		pts[i]=vector2(x,y);
	}
	vector2 pv = *min_element(pts.begin(), pts.end());

	ffor(i,n){
		pts[i].p = pts[i].x-pv.x;
		pts[i].q = pts[i].y-pv.y;
	}
	sort(pts.begin(),pts.end(),comp);

	stack<ll> st;
	st.push(0);
	st.push(1);
	for(ll i =2;i<pts.size();i++){
		ll se = st.top();
		st.pop();
		ll fi = st.top();
		while(ccw(pts[fi], pts[se], pts[i])<=0){
			se = fi;
			st.pop();
			if(st.empty())break;
			fi = st.top();
		}
		st.push(se);
		st.push(i);
	}

	vector<vector2> cvh(st.size());
	int k = 0;
	while(!st.empty()){
		cvh[k++]=pts[st.top()];
		st.pop();
	}
	circum(cvh,l);
}