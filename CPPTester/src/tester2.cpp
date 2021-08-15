#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int s, cnt;
	char c;
	scanf("%d",&s);
	for(int i=0;i<s;i++){
		scanf("%d",&cnt);
		while ((c = fgetc(stdin)) != EOF && c != '\n'){
			if(c != ' ')
			for(int k=0;k<cnt;k++){
				printf("%c",c);
			}
		}
		printf("\n");
	}
	
	return 0;
}
