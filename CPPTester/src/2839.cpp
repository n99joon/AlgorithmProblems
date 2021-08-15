#include <cstdio>
int main() {
	int t,k,a,p;
	scanf("%d",&t);
	k=t/5+(t%5)/3;
	p=t%5%3;
	a=p==0?k:
	  p==1?k+1:
	  p==2?k+2:-1;
	if(p==1)if(t/5<1)a=-1;
	if(p==2)if(t/5<2)a=-1;
	printf("%d",a);
}
