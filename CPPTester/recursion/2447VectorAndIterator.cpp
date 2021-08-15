#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;
vector<vector<string>> v;

void printStar(int n, int i,int t){
	if(n==3&&t){
		v[i].push_back("***");
		v[i+1].push_back("* *");
		v[i+2].push_back("***");
	} else if (n==3&&!t){
		v[i].push_back("   ");
		v[i+1].push_back("   ");
		v[i+2].push_back("   ");
	}
	else if(t){
		printStar(n/3,i,1);
		printStar(n/3,i,1);
		printStar(n/3,i,1);
		printStar(n/3,i+n/3,1);
		printStar(n/3,i+n/3,0);
		printStar(n/3,i+n/3,1);
		printStar(n/3,i+2*n/3,1);
		printStar(n/3,i+2*n/3,1);
		printStar(n/3,i+2*n/3,1);
	} else{
		printStar(n/3,i,0);
		printStar(n/3,i,0);
		printStar(n/3,i,0);
		printStar(n/3,i+n/3,0);
		printStar(n/3,i+n/3,0);
		printStar(n/3,i+n/3,0);
		printStar(n/3,i+2*n/3,0);
		printStar(n/3,i+2*n/3,0);
		printStar(n/3,i+2*n/3,0);
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int p=0;p<t;p++){
		vector<string> a;
		v.push_back(a);
	}
	printStar(t,0,1);
	for(vector<vector<string>>::iterator itr=v.begin();itr!=v.end();++itr){
		for(string k:*itr){
		cout<<k;
	}  
		cout<<"\n";
	}  
}
