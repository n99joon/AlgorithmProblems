#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

vector<int> s1;

void push(int t){
	s1.push_back(t);
}

void pop(){
	if(s1.size()==0) {
		cout << "-1\n";
		return;
	}
	cout << s1.back() << "\n";
	s1.pop_back();
}

void size(){
	cout << (s1.size()) << "\n";
}

void empty(){
	cout << (s1.size()>0?0:1) << "\n";
}

void top(){
	if(s1.size()==0) {
		cout << "-1\n";
		return;
	}
	cout << s1.back() << "\n";
}

int main(){
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n,k;
	char a[10];
	cin >> n;
	//cout << "n is " << n;
	for(int i=0;i<n;i++){
		//cout << " n = " << n;
		cin >> a;
		//cout << " A = " << a;
		if(strcmp(a,"push")==0){
				cin >> k;
				push(k);
		}else if(strcmp(a,"top")==0){
			top();
		}else if(strcmp(a,"size")==0){
			size();
		}else if(strcmp(a,"empty")==0){
			empty();
		}else if(strcmp(a,"pop")==0){
			pop();
		}
	}
}