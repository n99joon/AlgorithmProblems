#include <cstdio>
long long pow(long long n,long long e,long long mod){
	long long ans=1;
	for(;e;e>>=1,n=(n*n)%mod){
		if(e&1){
			ans=(ans*n)%mod;
		}
	}
	return ans;
}
int main(){
	long long n,e,m;
	scanf("%lld%lld%lld",&n,&e,&m);
	printf("%lld",pow(n,e,m));
}
