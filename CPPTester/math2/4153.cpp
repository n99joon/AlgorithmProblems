
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	while(a!=0){
		if(pow(max(max(a,b),c),2)*2==a*a+b*b+c*c)
			printf("right\n");
		else
			printf("wrong\n");
		scanf("%d%d%d",&a,&b,&c);
	}
} 