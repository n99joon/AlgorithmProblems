#include <cstdio>
#include <cstring>
int main(){
	int a,b,m=0,r=0,ans[10001]; //0 = prime
	memset(ans,0,10001*sizeof(int));
	ans[1]=1;
	//calculate all primes
	for(int k=2;k<100;k++){
		if(!ans[k]){
			for(int p=2;p*k<=10000;p++){
				ans[p*k]=1;
			}
		}
	}
	//printf("her8e");
	scanf("%d%d",&a,&b);
	for(;a<=b;a++){
		if(!ans[a]) {
			r+=a;
			if(!m) m=a;
		}
	}
	if(m==0) printf("-1");
	else{
		printf("%d\n%d",r,m);
	}
	return 0;
}