#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int t,k;
	scanf("%d",&t);
	vector<string> a;
	string s;
	while(t--){
		a.clear();
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			cin >> s >> s;
			a.push_back(s);
		}
		
		sort(a.begin(),a.end());
		
		string prv=" ";
		int cnt=0,ans=1;
		for(string str:a){
			if(str!=prv){
				ans*=cnt+1;
				cnt=1;
			}else{
				cnt++;
			}
			prv=str;
		}
		if(cnt)ans*=cnt+1;
		printf("%d\n",ans-1);
		
		
	}
}