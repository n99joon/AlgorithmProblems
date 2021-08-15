#include <cstdio>
int main(){
	long long cur=0,max=-1001;
	int x,t;
	scanf("%d",&t);
	scanf("%lld",&cur);
	max=cur;
	for(int i=0;i<t-1;i++){
		scanf("%d",&x);
		//printf("cur is %lld",cur);
		if(max<0 && x<0){
			if(x>max){
				max=x;
				cur=x;
			}
			continue;
		}
		if(x<0)
			if(cur+x>0)cur=cur+x;
			else cur=0;
		else if(cur>=0)cur=cur+x;
		else cur=x;
		if(cur>max)max=cur;
	}
	printf("%lld",max);
}