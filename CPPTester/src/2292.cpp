#include<cstdio>
#include<cmath>
int main(){
	int t;
	scanf("%d",&t);
	if(t==1)printf("1");
	else printf("%d",(int)(sqrt((t-2)*1/3+0.25)+0.5)+1);
}