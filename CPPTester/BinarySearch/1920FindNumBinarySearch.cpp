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
bool binarySearch(vector<int> & inp, int targ){
	int low = 0, high = inp.size()-1,mid;
	while(low<high){
		mid = (low+high)/2;
		if(inp[mid]==targ)return 1;
		//index is larger than target
		else if(inp[mid]>targ){
			high=mid;
		}
		else low=mid+1;
	}
	//cout << "targ" << targ <<endl;
	//cout << "low " << low << endl;
	if(inp[low]==targ)return 1;
	else return 0;
}

int main(){
	fastio;
	int a,t;
	cin >> a;
	vector<int> inp(a);
	ffor(i,a){
		cin >> inp[i];
	}
	sort(inp.begin(),inp.end());
	int b;
	cin >> b;
	//for(auto k : inp)cout << k << endl;
	while(b--){
		cin >> t;
		if(binarySearch(inp,t))cout<<1<<endl;
		else cout<<0<<endl;
	}
}