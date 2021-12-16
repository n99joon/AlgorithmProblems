#include <cstdio>
int main(){
	int t, max=1;
	scanf("%d",&t);
	int n[t];
	int dp[1001]={1001,};
	for(int i=1;i<1001;i++)dp[i]=0;
	for(int i=0;i<t;i++){
		scanf("%d",&n[i]);
		if(i==0)dp[1]=n[0];
		for(int j=i+1;j>=0;j--){
			if(dp[j]>n[i]&&n[i]>dp[j+1]){
				dp[j+1]=n[i];
				if(max<j+1)max=j+1;
			}
		}
	}
	for(auto& i:dp) printf("%d ",i);
	printf("%d",max);
}