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
#define SZ 360000
using namespace std;

vector<int> pi;
//Find pi[i] : In substring N[:i] inclusive, the max prefix length where prefix == suffix
void precalcPI(const string& N){
	int m = N.size();
	pi.assign(m,0);
	//KMP on N with N
	//start with begin = 1 cuz 0 will find itself
	int begin = 1, matched = 0;
	while(begin+matched < m){
		if(N[begin+matched]== N[matched]){
			matched++;
			pi[begin+matched-1]=matched;
		}
		else{
			if(matched==0){
				begin++;
			}
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
}


void doKMP(const string& H, const string& N,vector<int> & ret){
	int n = H.size(), m = N.size();
	int begin = 0, matched = 0;
	while (begin <= n-m){
		//if Haystack == Needle 
		if(matched < m && H[begin + matched] == N[matched]){
			++matched;
			if(matched == m)ret.push_back(begin);
		}
		else{
			if(matched == 0){
				begin++;
			}else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
}


int doKMP2(const string& H, const string & N){
	int n = H.size(), m = N.size();
	int matched = 0;
	//haystack traversal
	for(int i = 0; i < n; i++){
		// if N[matched] != H[i], 
		// reduce matched by pi[matched]
		while(matched > 0 && H[i] != N[matched]){// N[matched] = 맞은길이 바로 다음 인덱스
			matched = pi[matched - 1]; 
		}
		if(H[i]==N[matched]){
			++matched;
			if(matched == m){
				return 1;
				//ret.push_back(i-m+1);
				//matched = pi[matched-1];
			}
		}
	}
	return 0;
}

int main(){
	fastio;
	string N(SZ,'0');
	string H(SZ,'0');
	int n,inp;
	cin >> n;
	ffor(i,n){
		cin >> inp;
		N[inp]='1';
	}
	ffor(i,n){
		cin >> inp;
		H[inp]='1';
	}
	H+=H;
	precalcPI(N);
	if(doKMP2(H,N))cout<<"possible"<<endl;
	else cout << "impossible"<<endl;
}