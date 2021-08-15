#include <cstdio>
#include <math.h>
#define MIN(x,y) x>y?y:x
int findEx(int t, int y){
	return log(t)/log(y);
}

int findNum(int t, int y){
	int k=findEx(t,y),r=0;
	while (k--){
		r+=t/pow(y,k+1);
	}
	return r;
}

int main(){
	int n,k,fn,fk,fnk, tn, tk, tnk;
	scanf("%d%d",&n,&k);
	k=k>n-k?n-k:k;
	if(n==0 || k==0 || n==k)
		printf("0");
	else{
	fn=findNum(n,5);
	fk=findNum(k,5);
	fnk=findNum(n-k,5);
	tn = findNum(n,2);
	tk = findNum(k,2);
	tnk = findNum(n-k,2);
	printf("%d",MIN(fn-fk-fnk,tn-tk-tnk));
	}
}