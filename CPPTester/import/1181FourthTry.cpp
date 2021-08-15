#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(string x, string y){
	if(x.length()==y.length())
		return x<y;
	return x.length()<y.length();
}

int main(){
	int t;
	vector<string> a;
	cin >> t;
	for(int l=0;l<t;l++){
		string str;
		cin >> str;
		if(find(a.begin(), a.end(), str) == a.end())
			a.push_back(str);
	}
	sort(a.begin(),a.end(),comp);
	
	for (int i=0;i<a.size();i++){
		cout << a[i] <<'\n';
	}
}