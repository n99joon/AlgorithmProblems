#include <cstdio>
#define ll long long
ll pow(long long n,long long e,long long m){
	long long a=1;
	for(;e;e/=2,n=(n*n)%m)if(e&1)a=(a*n)%m;
	return a;}
main(){
	long long n,e,m;
	scanf("%lld%lld%lld",&n,&e,&m);
	printf("%lld",pow(n,e,m));}
