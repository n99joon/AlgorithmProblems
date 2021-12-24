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

/*******************************************
[              node 1 (0,14)               ]
[     node2 (0,7)   ][    node 3 (8,14)    ]
node n*2, node n*2+1,
....


******************************************/


//range minimum query
struct SEG{
	//array's length
	int n;
	//each segment's minimum
	vector<ll> rangeMin;
	SEG(const vector<ll>& array){
		n=array.size();
		//N*2 for leaf node ceiling till power of 2
		//N*2 for all the above nodes (2n-1)
		rangeMin.resize(n*4);
		init(array,0,n-1,1);
	}
	//when "node" represents array[left..right],
	//init subtree with "node" as root, and return the min in this segment 
	ll init(const vector<ll> & array ,int left, int right, int node){
		if(left==right)
			return rangeMin[node]=array[left];
		int mid = (left+right)/2;
		ll leftMin = init(array,left,mid,node*2);
		ll rightMin = init(array,mid+1,right,node*2+1);
		return rangeMin[node]=leftMin+rightMin;
	}
	//when node's range array[nodeLeft,nodeRight] is given,
	//find the min of overlapping range with array[left,right]
	ll query ( int left, int right, int node, int nodeLeft, int nodeRight){
		//no overlap
		if(right < nodeLeft || left > nodeRight) return 0;
		//node is within left,right
		if(left<=nodeLeft && right>=nodeRight){
			return rangeMin[node];
		}
		//else do recursion
		int mid = (nodeLeft+nodeRight)/2;
		return query(left,right,node*2,nodeLeft,mid)+
				  query(left,right,node*2+1,mid+1,nodeRight);
	}
	//to call query from outside
	ll query(int left, int right){
		return query(left,right,1,0,n-1);
	}
	//when array[index] = newValue, 
	//update segtree and return min of given range
	ll update(int index, ll newValue, int node, int nodeLeft, int nodeRight){
		//if index is not in range, ignore
		if(index < nodeLeft || index > nodeRight){
			return rangeMin[node];
		}
		//when it's down till leaf node
		if(nodeLeft == nodeRight){return rangeMin[node]=newValue;}
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] =
			update(index,newValue,node*2,nodeLeft,mid)+
			update(index,newValue,node*2+1,mid+1,nodeRight);
	}
	//update() from outside
	ll update(int index, ll newValue){
		return update(index, newValue, 1, 0, n-1);
	}
};

int main(){
	fastio;
	int n,m,k,q,a,b;
	ll l;
	cin >> n >> m >>k;
	vector<ll> array(n);
	ffor(i,n){
		cin >> array[i];
	}
	SEG * root = new SEG(array);
	/* debug */
	/*
	for(int p : root->rangeMin){
		cout << p <<" ";
	}
	cout << endl;
	for(int k:array){
		cout << k << " ";
	}*/
	ffor(i,m+k){
		cin >> q;
		if(q==1){
			cin >> a >> l;
			root->update(a-1,l);
		}
		else {
			cin >> a >> b;
			cout<<root->query(a-1,b-1)<<endl;
		}
	}
	
}