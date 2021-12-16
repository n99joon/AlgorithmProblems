#include <cstdio>
int main(){
	int a,b;
	do{
		scanf("%d %d",&a,&b);
		if(a==0 && b==0) break;
		if(a!= 0 && b%a==0)printf("factor\n");
		else if(b!= 0 && a%b==0)printf("multiple\n");
		else printf("neither\n");
	}while(1);
}