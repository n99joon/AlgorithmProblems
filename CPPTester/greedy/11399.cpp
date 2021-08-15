#include <cstdio>
#include <algorithm>
int main(){
	int t,sum=0,cu=0;
	scanf("%d",&t);
	int n[t];
	for(int i=0;i<t;i++){
		scanf("%d",&n[i]);
	}
	std::sort(n,n+t);
	for(int i=0;i<t;i++){
		cu+=n[i];
		sum+=cu;
	}
	printf("%d",sum);
}