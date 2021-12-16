#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define MAX 100001
using namespace std;

int in[MAX];
int post[MAX];
int n;

void solv(int fr, int to, int infr, int into){
	if(fr > to) return;
	int cur = post[to];
	cout << cur << " ";
	int idx = in[cur];

	solv(fr,fr+idx-infr-1,infr,idx-1);
	solv(fr+idx-infr,to-1,idx+1,into);
}

int main(){
	int n,k;
	cin >> n;
	
	ffor(i,n){
		cin >>k;
		in[k]=i;
	}
	ffor(i,n)cin >> post[i];
	
	solv(0,n-1,0,n-1);
}