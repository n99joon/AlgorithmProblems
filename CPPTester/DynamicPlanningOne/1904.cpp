#include <cstdio>
int a=1,b=2;
int main(){
	int t,temp;
	scanf("%d",&t);
	if(t==1) printf("%d",a);
	else if(t==2) printf("%d",b);
	else{
	while(t---2){
		temp=b;
		b=(a+b)%15746;
		a=temp%15746;
	}
	printf("%d",b);
	}
}