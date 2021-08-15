#include <cstdio>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
//record the index of smallest value
void init(vector<ll> &a, vector<int> &tree, int start, int end, int node){
	if(start==end) tree[node]=start;
	else{
		init(a,tree,start,(start+end)/2,node*2);
		init(a,tree,(start+end)/2+1,end,node*2+1);
		if (a[tree[node*2]] <= a[tree[node*2+1]]) 
            tree[node] = tree[node*2];
        else 
            tree[node] = tree[node*2+1];
	}
}
//find minimum height's index
int findMin(vector<ll> &a, vector<int> &tree,int node, int start, int end, int i, int j){
	if(i>end || j<start){
		return -1;
	}
	if(i<=start && end <= j){
		return tree[node];
	}
	int m1=findMin(a,tree,2*node,start,(start+end)/2,i,j);
	int m2=findMin(a,tree,2*node+1,(start+end)/2+1,end,i,j);
	if(m1==-1)return m2;
	else if(m2==-1)return m1;
	else{
		if(a[m1]<=a[m2]) return m1;
		else return m2;
	}
}
//find max area
ll findMax(vector<ll> &a, vector<int> &tree, int start, int end){
	int n=a.size();
	int m=findMin(a,tree,1,0,n-1,start,end);
	ll area=(ll)(end-start+1)*(ll)a[m]; //width = end-start+1, length = a[m]
	//if m is not the leftmost
	if(start<=m-1){
		ll temp=findMax(a,tree,start,m-1);
		if(area<temp)area=temp;
	}
	if(end >= m+1){
		ll temp = findMax(a,tree,m+1,end);
		if(area<temp)area=temp;
	}
	return area;
}
int main(){
	int n;
	ll k;
	while(1){
		scanf("%d",&n);
		if (n==0) break;
		vector<ll> a(n);
		for(int i=0;i<n;i++){
			scanf("%lld",&k);
			a[i]=k;
		}
		ll h=(ll)ceil(log2(n)+1);
		vector<int> tree(1<<h+1);
		init(a,tree,0,n-1,1);
		/*
		for(auto& p:a){
			printf("%lld ",p);
		}
		printf("\n");
		for(auto& p:tree){
			printf("%lld ",p);
		}
		*/
		printf("%lld\n",findMax(a,tree,0,n-1));
	}
}