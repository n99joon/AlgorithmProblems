#include <cstdio>
int t, N[41]={0},idx;
int main(){
	scanf("%d",&t);
	N[1]=1;
	for(int i=2;i<=40;i++){
		N[i]=N[i-1]+N[i-2];
	}
	while(t--){
		scanf("%d",&idx);
		if(idx==0) printf("1 0\n");
		else printf("%d %d\n",N[idx-1],N[idx]);
	}
}