#include <cstdio>
int k[4], t, min = 2e9, max = -2e9,n[11];

void solv(int pos, int sum, bool isMax){
	if(pos>=t-1) {
		if(sum>max)max=sum;
		if(sum<min)min=sum;
		return;
	}
	for(int i=pos+1;i<t;i++){
		if(isMax&&k[0]==0&&k[2]==0&&sum<max)return;
		if(!isMax&&k[1]==0&&k[3]==0&&sum>min)return;
		if(k[0]>0){
			k[0]--;
			solv(pos+1,sum+n[pos+1],isMax);
			k[0]++;
		} 
		if(k[1]>0){
			k[1]--;
			solv(pos+1,sum-n[pos+1],isMax);
			k[1]++;
		}
		if(k[2]>0){
			k[2]--;
			solv(pos+1,sum*n[pos+1],isMax);
			k[2]++;
		}
		if(k[3]>0){
			k[3]--;
			solv(pos+1,sum/n[pos+1],isMax);
			k[3]++;
		}
	}
}

int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n[i]);
	}
	for(int i=0;i<4;i++){
		scanf("%d",&k[i]);
	}
	
	
	solv(0,n[0],0);
	solv(0,n[0],1);
	
	printf("%d\n%d",max,min);
}