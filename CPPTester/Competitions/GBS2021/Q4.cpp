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

vector<ull> fwt;
ull n = 1e7;
ull gcd(ull a, ull b){
	if(b>a)swap(a,b);
	while(b>0){
		ull temp = a%b;
		a=b;
		b=temp;
	}
	return a;
}
void add(ull idx, ull val){
		while(idx<=n){
			fwt[idx]+=val;
			idx += (idx & -idx);
		}
	}
	//query = x ^ (x-1) while x!=0
ull query(ull idx){
	ull ret=0;
	while(idx!=0){
		ret+=fwt[idx];
		idx&=idx-1;
	}
	return ret;
}

vector<ull> segT;
//return new value of node with updated value
ull supdate(ull idx, ull newVal, ull node, ull lr, ull rr){
	//no overlap
	if(idx < lr || idx > rr){
		return segT[node];
	}
	//full overlap
	if(lr==rr){
		return segT[node]=newVal;
	}
	//else recurse
	ull mid = (lr+rr)/2;
	return segT[node]=gcd(supdate(idx,newVal,node*2,lr,mid),supdate(idx,newVal,node*2+1,mid+1,rr));
}

ull supdate(ull idx, ull newVal){
	return supdate(idx,newVal,1,0,n-1);
}

ull squery(ull lf,ull rf, ull node, ull lr, ull rr){
	//no overlap
	if(lf > rr || rf < lr){
		return 0;
	}
	//full overlap
	if(lf <=lr && rf >= rr){
		return segT[node];
	}
	//else recurse
	ull mid = (lr+rr)/2;
	return gcd(squery(lf,rf,node*2,lr,mid) ,squery(lf,rf,node*2+1,mid+1,rr));
}
ull squery(ull lf, ull rf){
	return squery(lf,rf,1,0,n-1);
}
int main(){
	fastio;
	ull a,d,q;
	cin >> a >> d >> q;
	fwt.assign(1e7+1,0);
	ull u = a;
	forr(i,1e7){
		add(i,u);
		u+=d;
	}
	
	segT.assign(1e7, 0);
	u = a;
	forr(i,1e6+1){
		supdate(i,u);
		u+=d;
	}
	
	ull qn,l,r;
	while(q--){
		cin >> qn >> l>>r;
		if(qn==1){
			cout<<query(r)-query(l-1)<<endl;
		}
		else{
			cout<<squery(l,r)<<endl;
		}
	}
}