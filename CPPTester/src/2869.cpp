#include <cstdio>
int main(){
	int A,B,V;scanf("%d %d %d",&A,&B,&V);
	double k=(double)(V-A)/(A-B);
	if((int)k==k) printf("%d",(int)k+1);
	else printf("%d",(int)k+2);
}