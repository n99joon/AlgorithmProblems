#include <cstdio>
#include <cstring>
int main(){
	int a[10001];
	memset(a,0,sizeof(int)*10001);
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a[n]++;
	}
	for(int k=1;k<10001;k++){
		for(int p=0;p<a[k];p++){
			printf("%d ",k);
		}
	}
}