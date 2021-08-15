#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string a,b;
	cin >> a >> b;
	int max=0,cnt=0;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			while(a[i+cnt]==b[j+cnt]){
				cout << "a is " << a[i+cnt]<<endl;
				cnt++;
				if(cnt>max)max=cnt;
				if(i+cnt >= a.length() || j+cnt >= b.length()) break;
			}
			cnt=0;
		}
	}
	printf("%d",max);
}