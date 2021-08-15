#include <cstdio>

int main(){
	int x,y,i,j,n;
	scanf("%d %d",&x,&y);
	int ar1[x][y];
	for(int t=0;t<x;t++)
		for(int u=0;u<y;u++){
			scanf("%d",&n);
			ar1[t][u]=n;
		}
	scanf("%d %d",&i,&j);
	int ar2[i][j];
	for(int t=0;t<i;t++)
		for(int u=0;u<j;u++){
			scanf("%d",&n);
			ar2[t][u]=n;
		}
	int r=0;
	for(int k=0;k<x;k++){
		for(int m=0;m<j;m++){
			for(int l=0;l<y;l++){
				r+=ar1[k][l]*ar2[l][m];
			}
			printf("%d ",r);
			r=0;
		}
		printf("\n");
	}
}