#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	int max=0;
	int dp[b.length()+1]={-1,};
	for(int i=1;i<=b.length();i++){
		dp[i]=1001;
	}
	
	vector<int> n[b.length()];
	//set up
	for(int i=0;i<b.length();i++){
		for(int j=0;j<a.length();j++){
			if(a[j]==b[i])n[i].push_back(j);
		}
	}
	/*
	for(auto& i:n){
		cout << "vector " << endl;
		for(auto& j:i) cout << j << " " << endl;
	}
	cout << "dp\n";
	
	for(auto& i:dp){
		cout << i << " ";
	}
	*/
	//calculate
	for(int i=0;i<b.length();i++){
		for(int k=n[i].size()-1;k>=0;k--){
			for(int j=i+1;j>=1;j--){
				if(dp[j]>n[i][k]&&dp[j-1]<n[i][k]){
					if(j>max)max=j;
					dp[j]=n[i][k];
				}
			}
		}
	}
	/*
	cout << "dp\n";
	
	for(auto& i:dp){
		cout << i << " ";
	}
	*/
	cout << max;

}