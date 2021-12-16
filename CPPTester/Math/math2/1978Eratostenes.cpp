#include <cstdio>
#include <cstring>
int main(){
	int t,k,cnt=0,ans[1001]; //0 = prime
	memset(ans,0,1001*sizeof(int));
	ans[1]=1;
	//calculate all primes
	for(int k=2;k<32;k++){
		if(!ans[k]){
			for(int p=2;p*k<=1000;p++){
				ans[p*k]=1;
				//if(p*k==971)printf("%d,%d",k,p);
			}
		}
	}
	//printf("her8e");
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		if(!ans[k]) cnt++;
		//printf("here");
	}
	//printf("971 is %d",ans[971]);
	printf("%d",cnt);
	return 0;
}