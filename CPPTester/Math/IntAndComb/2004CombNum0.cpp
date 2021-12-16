#include <cstdio>
#include <math.h>

int findEx(int t){
	return (int)(log(t)/log(2));
}
int findNum(int t){
	int k=findEx(t),r=0;
	while (k--){
		r+=t/pow(2,k+1);
	}
	return r;
}
int main(){
	int n,k,fn,fk,fnk;
	scanf("%d%d",&n,&k);
	fn=findNum(n);
	fk=findNum(k);
	fnk=findNum(n-k);
	printf("%d %d %d",fn,fk,fnk);
	printf("%d",fn-fk-fnk);
}