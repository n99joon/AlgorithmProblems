#include <cstdio>
int main(){
	int a,sum=0;
	char b;
	do{
		scanf("%d%c",&a,&b);
		sum+=a;
	}while(b!='-'&&b!=EOF && b!='\n');
	if(b=='-')
	do{
		scanf("%d%c",&a,&b);
		sum-=a;
	}while(b!=EOF && b!='\n');
	printf("%d",sum);
}