#include <cstdio>
int main(){
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("%d %d",a==c?e:c==e?a:c,b==d?f:d==f?b:d);
}