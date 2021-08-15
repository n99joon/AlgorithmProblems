#include <iostream>
#include <cstring>
#include <cmath>
#define b 10000

using namespace std;
int main(){
	int ans[b+1];
	memset(ans,0,(b+1)*sizeof(int));
	ans[1]=1;
	for(int k=2;k<=sqrt(b);k++){
		if(!ans[k]){
			for(int p=k*k;p<=b;p+=k){
				ans[p]=1;
			}
		}
	}
	
	int t,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		for(int p=k/2;p>0;p--){
			if(!ans[p]) if(!ans[k-p]) {
				printf("%d %d\n",p,k-p);
				break;
			}
		}
	}
	
	return 0;
}