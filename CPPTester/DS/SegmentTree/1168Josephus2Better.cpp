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
	vector<int> rangeMin;
	SEG(int n){
		this->n=n;
		//N*2 for leaf node ceiling till power of 2
		//N*2 for all the above nodes (2n-1)
		rangeMin.resize(n*4);
		vector<int> array(n,1);
		init(array,0,n-1,1);
	}
	//when "node" represents array[left..right],
	//init subtree with "node" as root, and return the min in this segment 
	int init(const vector<int> & array ,int left, int right, int node){
		if(left==right)
			return rangeMin[node]=array[left];
		int mid = (left+right)/2;
		int leftMin = init(array,left,mid,node*2);
		int rightMin = init(array,mid+1,right,node*2+1);
		return rangeMin[node]=leftMin+rightMin;
	}
	
	//when array[index] = newValue, 
	//update segtree and return min of given range
	void search(int node, int nodeLeft, int nodeRight, int k){
		
		if(nodeLeft== nodeRight){
			cout << nodeLeft+1;
			rangeMin[node]--;
			return;
		}
		int mid = (nodeLeft+nodeRight)/2;
		
		rangeMin[node]--;
		if(rangeMin[node*2]>=k){
			search(node*2,nodeLeft,mid,k);
		}else{
			search(node*2+1,mid+1,nodeRight,k-rangeMin[node*2]);
		}
	}
	
	//update() from outside
	void search(int k){
		search(1, 0, n-1, k);
	}
	
	
};

int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	SEG * root = new SEG(n);
	/* debug */
	/*
	for(int p : root->rangeMin){
		cout << p <<" ";
	}
	cout << endl;
	/*
	for(int k:array){
		cout << k << " ";
	}*/
	cout<<"<";
	
	int s = m;
	ffor(i,n){
		if(s>n-i)s%=n-i;
		if(s==0)s=n-i;
		root->search(s);
		s+=m-1;
		
		
		if(i!=n-1)cout<<", ";
		else cout<<">";
	}
}