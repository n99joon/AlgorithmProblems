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
	vector<pii> rangeMin;
	SEG(const vector<int>& array){
		n=array.size();
		//N*2 for leaf node ceiling till power of 2
		//N*2 for all the above nodes (2n-1)
		rangeMin.resize(n*4);
		init(array,0,n-1,1);
	}
	//when "node" represents array[left..right],
	//init subtree with "node" as root, and return the min in this segment 
	pii init(const vector<int> & array ,int left, int right, int node){
		if(left==right)
			return rangeMin[node]={array[left],array[left]};
		int mid = (left+right)/2;
		pii leftMin = init(array,left,mid,node*2);
		pii rightMin = init(array,mid+1,right,node*2+1);
		return rangeMin[node]={min(leftMin.fi,rightMin.fi),max(leftMin.se,rightMin.se)};
	}
	//when node's range array[nodeLeft,nodeRight] is given,
	//find the min of overlapping range with array[left,right]
	pii query ( int left, int right, int node, int nodeLeft, int nodeRight){
		//no overlap
		if(right < nodeLeft || left > nodeRight) return {INT_MAX,INT_MIN};
		//node is within left,right
		if(left<=nodeLeft && right>=nodeRight){
			return rangeMin[node];
		}
		//else do recursion
		int mid = (nodeLeft+nodeRight)/2;
		pii leftMin = query(left,right,node*2,nodeLeft,mid);
		pii rightMin = query(left,right,node*2+1,mid+1,nodeRight);
		return {min(leftMin.fi,rightMin.fi),max(leftMin.se,rightMin.se)};
	}
	//to call query from outside
	pii query(int left, int right){
		return query(left,right,1,0,n-1);
	}
	//when array[index] = newValue, 
	//update segtree and return min of given range
	pii update(int index, int newValue, int node, int nodeLeft, int nodeRight){
		//if index is not in range, ignore the update
		if(index < nodeLeft || index > nodeRight){
			return rangeMin[node];
		}
		//when it's down till leaf node
		if(nodeLeft == nodeRight){return rangeMin[node]={newValue,newValue};}
		int mid = (nodeLeft + nodeRight) / 2;
		pii leftMin = update(index,newValue,node*2,nodeLeft,mid);
		pii rightMin = update(index,newValue,node*2+1,mid+1,nodeRight);
		return rangeMin[node] = {min(leftMin.fi,rightMin.fi),max(leftMin.se,rightMin.se)};
	}
	//update() from outside
	pii update(int index, int newValue){
		return update(index, newValue, 1, 0, n-1);
	}
};

int main(){
	fastio;
	int n,m,q,a,b;
	cin >> n >> m;
	vector<int> array(n);
	ffor(i,n){
		cin >> array[i];
	}
	SEG * root = new SEG(array);
	ffor(i,m){
		cin >> a >> b;
		pii ans = root->query(a-1,b-1);
		cout<<ans.fi << " " << ans.se <<endl;
	}
	
}