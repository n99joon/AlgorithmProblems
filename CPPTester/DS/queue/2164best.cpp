#include <cstdio>
main(){
	int N,m=1;
	scanf("%d",&N);
	while(m<N)m<<=1;
	printf("%d ",(N<<1)-m);
}