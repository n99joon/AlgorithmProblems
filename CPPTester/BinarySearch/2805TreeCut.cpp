#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define ui unsigned int
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

ull lenS(int h,vector<int> & tree){
	ull sum=0;
	for(int k:tree){
		sum+= max(0,k-h);
	}
	return sum;
}
int main(){
	fastio;
	int n, m;
	cin >> n >> m;
	vector<int> tree(n);
	for(int i=0;i<n;i++){
		cin>>tree[i];
	}
	int low = 0,high = 1e9,mid;
	while(low<=high){
		mid = (low+high)/2;
		ull len = lenS(mid,tree);
		//cout<<len<<endl;
		if(len==m){
			cout<<mid;
			return 0;
		}
		if(len>m){
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	cout<<high;
	return 0;
}