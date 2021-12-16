#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n;
	char a[51];
	scanf("%d",&n);
	while(n--){
		vector<char> s1;
		s1.clear();
		bool ret = 1;
		scanf("%s",a);
		for(char k : a){
			if(k!='('&&k!=')')break;
			if(k=='('){
				s1.push_back(k);
				
			}
			else{
				if(s1.size()<1) {
					ret=0;
				}
				else s1.pop_back();
			}
		}
		if(!s1.empty())ret=0;
		if(ret) printf("%s","YES\n");
		else printf("%s","NO\n");
	}
}