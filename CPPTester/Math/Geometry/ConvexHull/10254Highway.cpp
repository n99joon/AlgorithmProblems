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


struct vector2{
	ll x,y;
	//상대적 위치 from pivot
	ll p,q; //p = x - pv.x , q = y - pv.y
	//prevent double from replacing vector using explicit in constructor
	//explicit vector2{int x_ = 0, int y_ = 0} : x(x_),y(y_){}
	vector2(ll xi =0, ll yi =0):x(xi),y(yi),p(0),q(0){};
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
	vector2 operator * (ll rhs) const{
		return vector2(x * rhs, y * rhs);
	}
	//length of a vector2
	ll norm() const {
		return hypot(x,y);
	}
	//return unit vector with same direction
	//exclude input of 0 vector
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	
	//dot & cross product
	ll dot(const vector2& rhs) const{
		return x * rhs.x + y * rhs.y;
	}
	ll cross(const vector2& rhs) const{
		return x * rhs.y - rhs.x * y;
	}
	ll crossP(const vector2& rhs) const{
		return p * rhs.q - rhs.p * q;
	}
	//projection of this vector onto rhs
	vector2 project(const vector2& rhs) const{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};
//원점 기준 , based in origin
ll ccw(vector2 a, vector2 b){
	return a.cross(b);
}
ll ccwP(vector2 a, vector2 b){
	return a.crossP(b);
}
//점 p 기준, based in point p
ll ccw(vector2 p, vector2 a, vector2 b){
	return ccw(a-p, b-p);
}
bool comp(const vector2 & a, const vector2 & b){
	ll cw= ccwP(a,b);
	if(cw!=0)return cw>0;
	
	if(a.x!=b.x){
		return b.x > a.x;
	}
	return b.y > a.y;
}

void diameter(const vector<vector2> & p){
	int n = p.size();
	//leftmost & rightmost point
	int left = min_element(p.begin(),p.end())-p.begin();
	int right = max_element(p.begin(),p.end())-p.begin();
	//left 와 right 에 수직선 붙이기. 
	//두 수직선은 정 반대 방향
	//A의 방향만 표현
	vector2 calipersA(0,1);
	double mx = (p[right] - p[left]).norm();
	int mr=right, ml = left;
	//toNext[i] = p[i] 에서 다음점까지의 방향을 나타내는 단위 벡터
	vector<vector2> toNext(n);
	ffor(i,n){
		toNext[i] = (p[(i+1)%n]-p[i]).normalize();
	}
	
}
	
int main(){
	fastio;
	ll n,x,y;
	cin >> n;
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
	
	diameter(cvh);
}