/*
https://bowbowbow.tistory.com/4
https://www.acmicpc.net/problem/10999
SegmentTree LazyPropagation
*/
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

vector<ll> segT;
vector<ll> toAdd;
int n;

//void init;
//return new value of node with updated value
void update(int lf, int rf, ll newVal, int node, int lr, int rr){
	if(toAdd[node]!=0){
		segT[node]+=(rr-lr+1)*toAdd[node];
		if(lr!=rr){
			toAdd[node*2]+=toAdd[node];
			toAdd[node*2+1]+=toAdd[node];
		}
		toAdd[node]=0;
	}
	
	//no overlap
	if(lf > rr || rf < lr){
		return;
	}
	//full overlap
	if(lf <= lr && rf >= rr){
		/*
		if(lf==rf){
			segT[node]=newVal;
			return;
		}*/
		segT[node]+=newVal*(rr-lr+1);
		if(lr != rr){
			toAdd[node*2]+=newVal;
			toAdd[node*2+1]+=newVal;
		}
		return;
	}
	//else recurse
	int mid = (lr+rr)/2;
	//toAdd[node]+=newVal*(min(rr,rf)-max(lr,lf)+1);
	update(lf,rf,newVal,node*2,lr,mid);
	update(lf,rf,newVal,node*2+1,mid+1,rr);
	
	segT[node]=segT[node*2]+segT[node*2+1];
}

void update(int lf, int rf, ll newVal){
	update(lf,rf,newVal,1,0,n-1);
}

ll query(int lf,int rf, int node, int lr, int rr){
	if(toAdd[node]!=0){
		segT[node]+=(rr-lr+1)*toAdd[node];
		if(lr!=rr){
			toAdd[node*2]+=toAdd[node];
			toAdd[node*2+1]+=toAdd[node];
		}
		toAdd[node]=0;
	}
	//no overlap
	if(lf > rr || rf < lr){
		return 0;
	}
	
	//full overlap
	if(lf <=lr && rf >= rr){
		return segT[node];
	}
	//else recurse
	int mid = (lr+rr)/2;
	return query(lf,rf,node*2,lr,mid) + query(lf,rf,node*2+1,mid+1,rr);
}
ll query(int lf, int rf){
	return query(lf,rf,1,0,n-1);
}
int main(){
	fastio;
	int m,k,q,a,b;
	ll c;
	cin >> n >> m >>k;
	segT.assign(4*n,0);
	toAdd.assign(4*n,0);
	ffor(i,n){
		cin >> c;
		update(i,i,c);
	}
	
	ffor(i,m+k){
		cin >> q;
		if(q==1){
			cin >> a >> b >> c;
			update(a-1,b-1,c);
		}
		else{
			cin >> a >> b;
			cout<< query(a-1,b-1)<<endl;
		}
	}
	/*
	for(auto k : segT){
		cout << k << " " ;
	}
	cout << endl;
	for(auto k : toAdd){
		cout << k << " " ;
	}*/
}
//https://www.acmicpc.net/source/5474422