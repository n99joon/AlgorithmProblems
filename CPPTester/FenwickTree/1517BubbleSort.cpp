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
	vector<int> fwt;
	FWT(int n){
		this->n = n;
		//size of fwt is n
		fwt.assign(n+1,0);
		//init(array);
	}
	
	//update = x + (x & -x) while < n
	void add(int idx){
		while(idx<=n){
			fwt[idx]++;
			idx += (idx & -idx);
		}
	}
	//query = x & (x-1) while x!=0
	int query(int idx){
		int ret=0;
		while(idx!=0){
			ret+=fwt[idx];
			idx&=idx-1;
		}
		return ret;
	}
};

int main(){
	fastio;
	int n;
	ull ans=0;
	cin >> n;
	FWT * root = new FWT(n);
	vector<int> inp(n);
	unordered_map<int,int> nToIdx;
	ffor(i,n){
		cin >> inp[i];
	}
	vector<int> srtd = inp;
	sort(srtd.begin(),srtd.end());
	ffor(i,n){
		nToIdx[srtd[i]]=i;
	}
	ffor(i,n){
		ans+=root->query(n)-root->query(nToIdx[inp[i]]+1);
		root->add(nToIdx[inp[i]]+1);
	}
	cout << ans;
}