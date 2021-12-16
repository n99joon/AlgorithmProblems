#include <cstdio>
int main(){
	int a,b,g,l;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++){
		if(a%i==0 && b%(a/i)==0){
			g=a/i;
			break;
		}
	}
	for(int i=1;i<=b;i++){
		if(a*i%b==0){
			l=a*i;
			break;
		}
	}
	printf("%d\n%d\n",g,l);
}