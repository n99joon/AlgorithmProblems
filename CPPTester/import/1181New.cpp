#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool comp(string x, string y){
	if(x.length() > y.length() || x.length()==y.length() && strcmp(&x[0],&y[0])>0 ) return 0;
	else return 1;
}
int main(){
	int t,s;
	scanf("%d",&t);
	string a[t];
	s=t;
	while(t--){
		cin >> a[t];
	}
	sort(a,a+s,comp);
	string prv="1";
	for(string k : a ) {
		if(k!=prv)printf("%s\n",&k[0]);
		prv=k;
	}
}