#include <cstdio>
#include <cmath>
int main(){
	int n;
	scanf("%d",&n);
	while((double)sqrt(n)>1){
		//printf("n is %d",n);
		if(n<4) {
			printf("%d\n",n);
			break;
		}
		for(int p=2;p<=sqrt(n);p++){
			if(n%p==0){
				printf("%d\n",p);
				n=n/p;
				break;
			}
			if(p==(int)sqrt(n)){
				printf("%d\n",n);
				n=0;
				break;
			}
		}
	}
}