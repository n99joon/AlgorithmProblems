#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
using namespace std;

int main() {
	fastio;
	int tc;
	cin >> tc;
	for(int i=1;i<=tc;i++){
		string a,b;
		cin >> a;//a=original
		b=a;//b=changed
		int len = a.length();
		int changed[len]={0,};
		
		for(int x=0;x<len;x++){
			if(changed[x])continue;
			for(int y=0;y<len;y++){
				if(x==y)continue;
				if(a[y]!=b[x] && b[y]!=b[x]){
					char temp=b[y];
					b[y]=b[x];
					b[x]=temp;
					changed[y]=1;
					changed[x]=1;
					break;
				}
			}
		}
		int flag = 0;
		for(int x=0;x<len;x++){
			if(a[x]==b[x]){
				flag=1;
				break;
			}
		}
		if(!flag){
			cout << "Case #" << i << ": " << b << endl;
		}else{
			cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
		}
	}
	
}
