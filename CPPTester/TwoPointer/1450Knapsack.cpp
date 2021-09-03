#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
using namespace std;
int n,c;
void findSum(vector<int> &v,vector<int> &s, int size, int idx,int sum){
	if(sum>c){
		return;
	}else if(idx==size){
		s.push_back(sum);
		return;
	}
	findSum(v,s,size,idx+1,sum);
	findSum(v,s,size,idx+1,sum+v[idx]);
}
int main() {
	fastio;
	cin >> n >> c;
	vector<int> arr,vf,vs,sf,ss;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		if(k<=c) 
			arr.push_back(k);
	}
	int size = arr.size();
	if(size<=1) {
		cout << 1 + size;
		return 0;
	}
	for(int i=0;i<size;i++)
		(i>=size/2?vs:vf).push_back(arr[i]);
	int fsize = vf.size();
	int ssize = vs.size();
	
	findSum(vf,sf,fsize,0,0);
	findSum(vs,ss,ssize,0,0);
	
	sort(sf.begin(),sf.end());
	/*
	for(auto a:ss){
		cout << a << " ";
	}*/
	int ret=0;
	for(int i=0;i<ss.size();i++){
			ret+=upper_bound(sf.begin(),sf.end(),c-ss[i])-sf.begin();
	}
	
	cout << ret;
}