#include <cstdio>
int main(){
	int N,m=1;
	scanf("%d",&N);
	while(m<N)m<<=1;
	printf("%d\n",(m==N)?N:(N<<1)-m);
	return 0;
}