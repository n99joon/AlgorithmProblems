#include <cstdio>
long p[101]={1,1,1,2,2,3,4,5,7,9,};
int main(){
	int t,n;
	scanf("%d",&t);
	for(int i=10;i<100;i++){
		p[i]=p[i-1]+p[i-5];
	}
	while(t--){
		scanf("%d",&n);
		printf("%ld\n",p[n-1]);
	}
}