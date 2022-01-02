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
#define mod 1000000007LL //1e9+7
using namespace std;
struct matrix{
	ll m[2][2];
	matrix(ll a=0,ll b=0, ll c=0,ll d=0){
		m[0][0]=a;
		m[0][1]=b;
		m[1][0]=c;
		m[1][1]=d;
	}
	
	void print(){
		cout << m[0][0] << " " <<m[0][1]<<endl;
		cout << m[1][0] << " " <<m[1][1]<<endl;
	}
};

matrix mtrx;

matrix * mult(matrix m1,matrix m2){
	matrix * ret = new matrix();
	ffor(i,2){
		ffor(j,2){
			ret->m[i][j]+=m1.m[i][0]*m2.m[0][j]%mod;
			ret->m[i][j]=(ret->m[i][j]+mod)%mod;
			ret->m[i][j]+=m1.m[i][1]*m2.m[1][j]%mod;
			ret->m[i][j]=(ret->m[i][j]+mod)%mod;
		}
	}
	//cout << "ret is " << ret->m[0][0] << " " <<ret->m[0][1] <<endl << ret->m[1][0] << " " <<ret->m[1][1] << endl;
	return ret;
}

int ans(matrix a){
	matrix x = *(new matrix(1,0,1,0));
	return mult(a,x)->m[0][0];
}

int doCalc(ull n){
	matrix * x = new matrix(1,0,0,1);
	while(n){
		if(n&1){
			x = mult(*x,mtrx);
		}
		mtrx=*mult(mtrx,mtrx);
		//x->print();
		n/=2;
	}
	return ans(*x);
}

int main(){
	fastio;
	ull n;
	cin >> n;
	if(n%2==1){
		cout << 0;
		return 0;
	}
	mtrx=*(new matrix(4,-1,1,0));
	
	//cout << mtrx.m[0][0];
	//cout << ans(mtrx)<<endl;
	cout << doCalc(n/2);
}