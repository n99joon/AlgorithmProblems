#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 6001
#define fi first
#define se second
#define eb 0.000000001
using namespace std;
int xmov[4] = {1,0,-1,0};
int ymov[4] = {0,1,0,-1};

int main(){
	fastio;
	int n;
	cin >> n;
	ffor(i,n){
		if(i==0 || i==n-1){
			ffor(j,n)cout<<"*";
			cout<<endl;
		}
		else{
			ffor(j,n){
				if(j==0||j==n-1||j==i||j==n-1-i)cout<<"*";
				else cout<<" ";
			}
			cout<<endl;
		}
	}
}