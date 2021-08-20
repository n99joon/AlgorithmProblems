#include <cstdio>
#define MINT(x,y,z) (x>y?(y>z?z:y):(x>z?z:x))
#define MIN(x,y) (x>y?y:x)
long n[1000001]={0,};
int main(){
	int t;
	scanf("%d",&t);
	for(int i=2;i<=t;i++){
		if(i%3==0 && i%2==0){
			n[i]=MINT(n[i/3],n[i/2],n[i-1])+1;
		}else if(i%2==0){
			n[i]=MIN(n[i-1],n[i/2])+1;
		}else if(i%3==0){
			n[i]=MIN(n[i-1],n[i/3])+1;
		}
		else n[i]=n[i-1]+1;
	}
	printf("%ld",n[t]);
}