#include <cstdio>
int b=0,w=0;
int ar[128][128];
void check(int x, int y, int size){
	//printf("%d %d\n",x,y);
	int worb=ar[x][y]; //worb 0=w
	if(size==1){
		if(worb)b++;
		else w++;
	}else{
		for(int i=x;i<x+size;i++)
			for(int j=y;j<y+size;j++){
				if(ar[i][j]!=worb){
					//printf("h %d %d %d\n",x,y,size);
					check(x,y,size/2);
					check(x+size/2,y,size/2);
					check(x,y+size/2,size/2);
					check(x+size/2,y+size/2,size/2);
					return;
				}
			}
		if(worb)b++;
		else w++;
		return;
	}
}
int main(){
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&k);
			ar[i][j]=k;
		}
	check(0,0,n);
	printf("%d %d",w,b);
}