#include <cstdio>
int f(int k){
	for(int i=k-1;i>0;i--)k*=i;
	return k;
}
main(){
	int x,y;
	scanf("%d%d",&x,&y);
	if(x==y||x==0||y==0)printf("1");
	else printf("%d",f(x)/f(y)/f(x-y));
}