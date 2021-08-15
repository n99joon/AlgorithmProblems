#include <cstdio>
#define mod 1000000007LL
typedef long long ll;
ll pow(ll n,ll e,ll m){
	ll ans=1;
	for(;e;e/=2,n=(n*n)%m){
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
	if(n==k || k==0)printf("1");
	else if(k==1 || k==n-1)printf("%lld",n);
	else{
		k=n-k>k?k:n-k;
		u=n;
	
	ll facn=1,fack,facnk;
	for(int i=2;i<=n;i++){
		facn=(facn*i)%mod;
		if(i==k)fack=facn;
		if(i==(n-k))facnk=facn;
		//printf("facn= %lld\n",facn);
	}
			//printf("fack= %lld\n",fack);
			//printf("facnk= %lld\n",facnk);
		fack=pow(fack,mod-2,mod);
		facnk=pow(facnk,mod-2,mod);
		ans=(((facn*fack)%mod)*facnk)%mod;
		printf("%lld\n",ans);
	}
	
	//printf("%lld %lld",mod,mod-2);
}