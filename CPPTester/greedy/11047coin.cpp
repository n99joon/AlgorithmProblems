#include <cstdio>
int main(){
	int t,s,k[10],ans=0;
	scanf("%d%d",&t,&s);
	for(int i=0;i<t;i++){
		scanf("%d",&k[i]);
	}
	for(int i=t-1;i>=0;i--){
		if(s/k[i]>0){
			ans+=s/k[i];
			s%=k[i];
		}
		if(s==0) break;
	}	
	printf("%d",ans);
}