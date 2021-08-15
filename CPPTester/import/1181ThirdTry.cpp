#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int s=t;
	char k[t][55];
	for(int i=0;i<t;i++){
		scanf("%s",&k[i][0]);
	}
	for(int l=0;l<s;l++){
		for(int p=0;p<l-1;p++){
			char temp[55];
			if(strlen(k[p])>strlen(k[p+1]) || strlen(k[p])==strlen(k[p+1]) && strcmp(k[p],k[p+1])>0) {
				strcpy(temp, k[p]);
				strcpy(&k[p][0],k[p+1]);
				strcpy(&k[p+1][0],temp);
			}
		}
	}
	while(t--){
		printf("%s ",k[s-t-1]);
	}
}