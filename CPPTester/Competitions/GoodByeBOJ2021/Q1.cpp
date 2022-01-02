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
bool primes[10002];

int main(){
	int i=2;
	int targ;
	cin >> targ;
	primes[0]=true;
	primes[1]=true;
	while(i<10001){
		while(primes[i])i++;
		for(int j=i*i;j<10001;j+=i){
			primes[j]=true;
		}
		i++;
	}
	vector<int> pr;
	ffor(i,10002){
		if(!primes[i])pr.push_back(i);
	}
	/*
	for(auto k : pr){
		cout << k << " ";
	}*/
	//int ans=1e9;
	ffor(i,pr.size()-1){
		//if(pr[i]*pr[i]>ans)break;
		if(pr[i]*pr[i+1]>targ){
			cout<<pr[i]*pr[i+1];
			return 0;
		}
	}
	//cout << ans;
}