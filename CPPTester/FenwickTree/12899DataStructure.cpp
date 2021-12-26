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
#define mod 1000000007ULL
using namespace std;

/*******************************************
[                   node 16 (1,16) (10000)                ]
[       node2 (1,8) (1000)        ]
[ node 4(1,4)(100)]
[n2(1,2)(10)]      [n6(110)]

....
query = x ^ (x-1) while x!=0
update = x + (x & -x) while < n
******************************************/


//range minimum query
struct FWT{
	//array's length
	int n;
	//each segment's minimum
	vector<ll> fwt;
	FWT(){
		n = 2e6;
		//size of fwt is n
		fwt.assign(n+1,0);
		//init(array);
	}
	
	//update = x + (x & -x) while < n
	void add(int idx, int k){
		while(idx<=n){
			fwt[idx]+=k;
			idx += (idx & -idx);
		}
	}
	//query = x & (x-1) while x!=0
	ll query(int idx){
		ll ret=0;
		while(idx!=0){
			ret+=fwt[idx];
			idx&=idx-1;
		}
		return ret;
	}
	
	void findkth(int k){
		int low = 0, high = n,mid;
		while(low<=high){
			mid = (low+high)/2;
			if(query(mid)>=k){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		cout << low<<endl;
		add(low,-1);
	}
	/*
	void printFWT(){
		cout << "print fwt: ";
		forr(i,n){
			cout << fwt[i] << " ";
		}
	}*/
};

int main(){
	fastio;
	int n,m,q,a,b,c,inp;
	
	cin >> n;
	//vector<int> inp(n+1);
	FWT * root = new FWT();

	forr(i,n){
		cin >> q >> a;
		if(q ==1){
			root->add(a,1);
		}
		else{
			root->findkth(a);
		}
	}
}