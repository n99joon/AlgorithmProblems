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
vector<int> score;
vector<int> cur;

ull canGet(const string & s, ull p){
	ull point = 0;
	char fir, las;
	stack<char> st;
	fir=s[0];
	las = s[s.length()-1];
	ffor(i,s.length()){
		if(!st.empty()){
			if(st.top()=='('){
				if(s[i]==')'){
					point++;
					st.pop();
				}else{
					continue;
				}
			} 
		}else{
			if(s[i]=='(')st.push('(');
		}
	}
	point*=p;
	if(fir == ')' && las=='(' && p>1)point+=(p-1);
	return point;
}
int main(){
	fastio;
	ull n,k;
	cin >> n >> k;
	//char fir, las;
	string s,d;
	ull p;
	cin >> s >> p;
	ull bc = canGet(s,p);
	cin >> d >> p;
	ull dr = canGet(d,p);
	ull canBuy = 0;
	ull bought=0;
	//cout << bc<<endl;
	//cout << dr << endl;
	if(bc>=k && dr>=k){
		cout<<n;
		return 0;
	}
	while(bc >= k && canBuy<n){
		bought = bc/k;
		canBuy += bought;
		bc%=k;
		bc+=dr*bought;
	}
	canBuy = canBuy>n?n:canBuy;
	cout << canBuy;
	
}