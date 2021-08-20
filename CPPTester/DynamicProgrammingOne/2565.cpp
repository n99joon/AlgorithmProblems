#include <cstdio>
int main(){
	int t,ans=0;
	scanf("%d",&t);
	int n[t+1][2]={0,},dp[501][501]={0,},num[501]={0,};
	for(int i=0;i<t;i++){
		scanf("%d%d",&n[i][0],&n[i][1]);
	}
	int max=0,maxIdx=-1;
	//calculate # of overlapping for each index
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			if(j!=i){
				//if crossed
				if((n[i][0]-n[j][0])*(n[i][1]-n[j][1])<0){
					dp[i][j]=1;
					num[i]+=1;
				}
			}
		}
		if(num[i]>max){
			max=num[i];
			maxIdx=i;
		}
	}
	for(auto& n: num) printf("n is %d\n",n);
		printf("done\n");
	int k=0;
	while(maxIdx!=-1){
		num[maxIdx]=0;
		max=0;
		k=maxIdx;
		maxIdx=-1;
		for(auto& n: num) printf("n is %d\n",n);
		printf("done\n");
		for(int i=0;i<t;i++){
			if(dp[k][i]==1)num[i]--;
			if(num[i]>max){
				max=num[i];
				maxIdx=i;
			}
		}
		ans++;
	}
	
	printf("%d",ans);
}