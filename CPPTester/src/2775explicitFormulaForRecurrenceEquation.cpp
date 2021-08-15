#include <cstdio>

int main(){
	int t,k,n,c,h;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&k,&n);
		int a[k+1][n];
		c=n; h=k+1;
		while(c--)a[0][c]=c+1;
		while(h--)a[h][0]=1;
		for(int p=1;p<k+1;p++){
			for(int l=1;l<n;l++)a[p][l]=a[p-1][l]+a[p][l-1];
		}
		printf("%d\n",a[k][n-1]);
	}
}

//https://www.youtube.com/watch?v=wXaEnbZkGY0
/*
1st see if we can find pattern
2nd homogeneous
*/