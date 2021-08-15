#include <cstdio>
int main(){
	long t,cur=2e9,sum=0;
	scanf("%d",&t);
	int o[t],d[t-1];
	for(int i=0;i<t-1;i++)
		scanf("%d",&d[i]);
	
	for(int i=0;i<t;i++)
		scanf("%d",&o[i]);
	
	for(int i=0;i<t-1;i++){
		if(o[i]<cur)cur=o[i];
		sum+=cur*d[i];
	}
	printf("%ld",sum);
}