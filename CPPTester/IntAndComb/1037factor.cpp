#include <cstdio>
main(){
	int t,m=2e9,M=0,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		if(k>M)M=k;
		if(k<m)m=k;
	}
	printf("%d",m*M);
}