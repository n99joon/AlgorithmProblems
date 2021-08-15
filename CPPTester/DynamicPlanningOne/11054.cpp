#include <cstdio>
int main(){
	int t;
	scanf("%d",&t);
	int n[t];
	int dpD[1001]={0,},dpU[1001]={0,};
	int max[t][2]={0,},maxU=1,maxD=1,ans=0;
	//int max=0;
	for(int i=1;i<1001;i++){
		dpU[i]=1001;
		dpD[i]=1001;
	}
	//increasing
	for(int i=0;i<t;i++){
		scanf("%d",&n[i]);
		if(i==0)dpU[1]=n[0];
		for(int j=i;j>=0;j--){
			if(dpU[j]<n[i]&&n[i]<dpU[j+1]){
				dpU[j+1]=n[i];
				if(maxU<j+1){
					maxU=j+1;
					max[i][0]=j+1;
				}
			}
		}
		if(max[i][0]==0)max[i][0]=maxU;
	}
	//decreasing
	for(int i=t-1;i>=0;i--){
		if(i==t-1)dpD[1]=n[t-1];
		for(int j=t-1-i;j>=0;j--){
			if(dpD[j]<n[i]&&n[i]<dpD[j+1]){
				dpD[j+1]=n[i];
				if(maxD<j+1){
					maxD=j+1;
					max[i][1]=j+1;
				}
			}
		}
		if(max[i][1]==0)max[i][1]=maxD;
	}
	/*
	for(auto& h:dpU) printf("%d ",h);
	printf("\n");
	for(auto& h:dpD) printf("%d ",h);
	*/
	for(int i=0;i<t;i++){
		if(max[i][0]+max[i][1]-1>ans)ans=max[i][0]+max[i][1]-1;
	}
	printf("%d",ans);
}