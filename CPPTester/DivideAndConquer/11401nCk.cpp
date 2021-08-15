#include <cstdio>
#define mod 1000000007LL
typedef long long ll;
ll pow(ll n,ll e,ll m){
	ll ans=1;
	for(;e;e>>=1,n=(n*n)%m){
		if(e&1){
			ans=(ans*n)%m;
		}
	}
	//printf("ans is %lld\n",ans);
	return ans;
	
}
int main(){
	ll n,k,ans=1,u,d=1;
	scanf("%lld%lld",&n,&k);
	k=n-k>k?k:n-k;
	u=n;
	while(ans<mod && d<=k){
		ans=ans*(u--)/(d++);
	}
	
	while(d<=k){
		ans=(((ans*u)%mod)*(pow(d,mod-2,mod)))%mod;
		u--;
		d++;
	}
	printf("%lld\n",ans);
	//printf("%lld %lld",mod,mod-2);
}