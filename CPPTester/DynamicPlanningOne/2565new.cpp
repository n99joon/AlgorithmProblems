#include <cstdio>
#include <algorithm>
using namespace std;
struct line{
	int x,y;
};

bool comp(line i,line j){
	return i.x<j.x;
}
int main(){
	int t;
	scanf("%d",&t);
	line n[t];
	for(int i=0;i<t;i++){
		scanf("%d%d",&n[i].x,&n[i].y);
	}	
	sort(n,n+t,comp);
	for(auto& k:n)printf("it is %d %d \n",k.x, k.y);
	int dp[t+1]={0,},max=0;
	for(int i=1;i<t+1;i++){
		dp[i]=501;
	}
	for(int i=0;i<t;i++){
		
		if(i==0)dp[1]=n[0].y;
		for(int j=i+1;j>=0;j--){
			if(dp[j]<n[i].y&&n[i].y<dp[j+1]){
				dp[j+1]=n[i].y;
				if(max<j+1)max=j+1;
			}
		}
		for(auto& h:dp)printf("cur dp is %d \n", h);
		printf("max is %d",max);
	}
	
	printf("%d",t-max);
}