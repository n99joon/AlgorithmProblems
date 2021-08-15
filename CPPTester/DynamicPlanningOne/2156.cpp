#include <cstdio>
#define MAX(x,y) (x>y?x:y)
int main(){
	int t;
	scanf("%d",&t);
	int p[t][4]={0,};
	int n[t];
	for(int i=0;i<t;i++){
		scanf("%d",&n[i]);
		if(i==1){
			p[1][0]=0;
			p[1][1]=n[0]+n[1];
			p[1][2]=n[1];
			p[1][3]=n[0];
		} if(i>1){
			p[i][0]=MAX(p[i-1][0],p[i-1][3]);
			p[i][1]=p[i-1][2]+n[i];
			p[i][2]=MAX(p[i-1][0],p[i-1][3])+n[i];
			p[i][3]=MAX(p[i-1][1],p[i-1][2]);
		}
	}
	if(t==1)printf("%d",n[0]);
	else {
		int max=0;
		for(int i=0;i<4;i++){
			if(p[t-1][i]>max)max=p[t-1][i];
		}
		printf("%d",max);}
}