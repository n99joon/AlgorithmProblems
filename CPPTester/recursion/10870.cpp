#include <cstdio>
#include <cmath>
int main(){
	int f;
	scanf("%d",&f);
	if(f==0)printf("0");else
	printf("%d",(int)(1/sqrt(5)*(pow((1+sqrt(5))/2,f)-pow((1-sqrt(5))/2,f))));
}