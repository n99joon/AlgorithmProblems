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
	//swap
	void swap(vector2 & a){
		double tx=x,ty=y;
		x=a.x;
		y=a.y;
		a.x=tx;
		a.y=ty;
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
typedef vector<vector2> polygon;
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

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d){
	double ab = ccw(a,b,c) * ccw(a,b,d);
	double cd = ccw(c,d,a) * ccw(c,d,b);
	//if on one line or intersect on point
	if(ab==0 && cd==0){
		if(b<a)a.swap(b);
		if(d<c)c.swap(d);
		return !(b<c || d<a);
	}
	return ab<=0 && cd<=0;
}

bool isInside(vector2 q, const vector<vector2> & p){
	int crosses = 0;
	ffor(i,p.size()){
		int j = (i + 1)%p.size();
		//(p[i],p[j])가 q에서 시작하는 반직선을 세로로 가로지르는가?
		if((p[i].y > q.y) != (p[j].y > q.y)){//반직선을 아주아주 조금 위로 올렸다고 가정 (둘다 같거나 하나 겹치고 하나 아래면 카운트 X)
			//가로지르는 x 좌표를 계산
			double atX  = (p[j].x - p[i].x) * (q.y - p[i].y)/(p[j].y - p[i].y) + p[i].x; //p[i] 에서 p[j] 까지 x 거리를 p[i]에서 q 까지 y의 비율만큼 곱함
			if(q.x < atX) ++crosses;
		}
	}
	return crosses%2>0;
}

bool solv(const vector<vector2> & w,const vector<vector2> & b){
	int ws = w.size();
	int bs = b.size();
	ffor(i,ws){
		ffor(j,bs){
			if(segmentIntersects(w[i],w[(i+1)%ws],b[j],b[(j+1)%bs])){
				//cout << (ll)w[i].x << " " <<(ll)w[i].y << " " <<w[(i+1)%ws].x << " " <<w[(i+1)%ws].y << " " <<(ll)b[j].x << " " <<(ll)b[j].y << " " << b[(j+1)%bs].x << " " <<b[(j+1)%bs].y<<endl;
				return false;
			}
		}
	}
	return true;
}

polygon CH(int n){
	int x,y;
	vector<vector2> pts(n);
	ffor(i,n){
		cin >> x >> y;
		pts[i]=vector2(x,y);
	}
	if(n<=2) return pts;
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
	return cvh;
}
	
int main(){
	fastio;
	int t,b,w,x,ans;
	cin >> t;
	while(t--){
		ans = 0;
		cin >> b >> w;
		polygon black = CH(b);
		polygon white = CH(w);
	for(auto a : black)if(isInside(a,white)){ans=1;cout<<"black in white"<<endl;}
		for(auto a : white)if(isInside(a,black)){ans=1;cout<<"w in b"<<endl;}
		if(!solv(black,white)){
			ans=1;
			cout << "intersect"<<endl;
		}
		if(ans)cout<<"NO"<<endl;
		else cout <<"YES"<<endl;
	}
}