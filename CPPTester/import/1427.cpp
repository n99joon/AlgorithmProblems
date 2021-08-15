#include <cstdio>
int main(){
	char c;
	int k[10]={0};
	while(scanf("%c",&c)&&c!='\n'&&c!=EOF&&c!=' '){
		k[c-'0']++;
	}
	int p=10;
	while(p--){
		for(int a=0;a<k[p];a++) printf("%d",p);
	}
}