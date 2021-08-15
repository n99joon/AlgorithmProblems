#include <cstdio>
int main(){
	int t,H,W,N;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	scanf("%d%d%d",&H,&W,&N);
	W=N%H==0?H:N%H;
	printf("%d\n",(N-1)/H+1+W*100);}
}