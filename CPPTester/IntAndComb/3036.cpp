#include <cstdio>
int GCD(int x, int y){
	if(y==0)return x;
	return GCD(y,x%y);
}
int main(){
	int t,k;
	scanf("%d",&t);
	int n[t];
	for(int i=0;i<t;i++){
		scanf("%d",&n[i]);
		if(i>0){
		k=GCD(n[0],n[i]);
		if(i!=0)printf("%d/%d\n",n[0]/k,n[i]/k);
		}
	}
	
}