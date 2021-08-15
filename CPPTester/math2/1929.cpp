#include <cstdio>
#include <cstring>
#include <cmath>
int main(){
	int a,b; //0 = prime
	scanf("%d%d",&a,&b);
	int ans[b+1];
	memset(ans,0,(b+1)*sizeof(int));
	ans[1]=1;
	//calculate all primes
	for(int k=2;k<=sqrt(b);k++){
		if(!ans[k]){
			for(int p=k*k;p<=b;p+=k){
				ans[p]=1;
			}
		}
	}
	while(a++<=b){
		if(!ans[a-1]) printf("%d\n",a-1);
	}
	return 0;
}
