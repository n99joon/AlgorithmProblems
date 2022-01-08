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
int ti(char a){
	return a-'0';
}

int main(){
	fastio;
	string x;
	cin >> x;
	int up = 0; //1 = up , 0 = down
	if((ti(x[1])-ti(x[0]))<=0 || (ti(x[x.length()-1])-ti(x[x.length()-2]))>=0){
		cout<<"NON ALPSOO";
			return 0;
	}
	ffor(i,x.length()-2){
		if(abs(ti(x[i])-ti(x[i+1])) == abs(ti(x[i+1])-ti(x[i+2])))continue;
		
		if((ti(x[i])-ti(x[i+1])) *(ti(x[i+1])-ti(x[i+2])) >=0){
			cout<<"NON ALPSOO";
			return 0;
		}
	}
	cout<<"ALPSOO";
}