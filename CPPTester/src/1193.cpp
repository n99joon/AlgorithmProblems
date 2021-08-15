#include <cstdio>
#include <cmath>
int main(){
	int t,x,y,k,m;
	scanf("%d",&t);
	x=(int)(sqrt(2*t-1.75)-0.5);
	y=1+0.5*(pow(x,2)+x);
	k=x+1-(t-y);
	m=1+t-y;
	if(x%2==0) printf("%d%c%d",k,'/',m); 
	else printf("%d%c%d",m,'/',k); 
}