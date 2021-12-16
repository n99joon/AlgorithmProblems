
#include <iostream>
using namespace std;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	char a[101];
	char s1[101];
	while(cin.getline(a,101,'\n')){
		int flag=1,idx=0;
		if(a[0]=='\0') continue;
		if(a[0]=='.') break;
		for(char t:a){
			if(t=='(' || t=='['){
				s1[idx++]=t;
			}
			else if(t==')' || t==']'){
				if(t==')'){
					if(idx<=0 || s1[idx-1]!='(') flag=0;
					else idx--;
				} else if(t==']'){
					if(idx<=0 || s1[idx-1]!='[') flag=0;
					else idx--;
				}
			}
			if(t=='\0')break;
		}
		if(idx!=0)flag=0;
		if(flag)cout <<"yes\n";
		else cout << "no\n";
	}
}