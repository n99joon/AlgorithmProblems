#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

bool comp(string x, string y){
	if(x.length()==y.length())
		return x<y;
	return x.length()<y.length();
}

int main(){
	int t;
	scanf("%d",&t);
	vector<string> a;
	
	
	for(int l=0;l<t;l++){
		string str;
		cin >> str;
		a.push_back(str);
	}
	sort(a.begin(),a.end(),comp);
	
	int cnt=0;
	for (int h=0; h<t;h++){
		if(h==0) {
			cout << a[h] << "\n";
			}
		else
		if(a[h]!=a[h-1]){
			cout << a[h] << "\n";
		}
	}
}