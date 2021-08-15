#include <cstdio>
#include <string>
using namespace std;
int main(){
	int t,d,p,c;
	scanf("%d",&t);
	d=to_string(t).length();
	for(int a=t-d*9;a<t;a++){
		p=0;
		c=to_string(a).length();;
		while(c--)
			p+=(int)to_string(a)[c]-'0';
		if(p+a==t){
			printf("%d",a);
			break;
		}
		if(a==t-1)printf("0");
	}
}