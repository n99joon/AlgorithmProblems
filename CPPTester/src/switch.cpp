#include <cstdio>
#include <stdlib.h>
#include <cstdlib>

int main(){
	char t;
	int ans=0;
	while(scanf("%c",&t) != 0 && t!='\n'){
		switch(t){
			case 'A' ... 'C':
				ans += 3;
				break;
			case 'D' ... 'F':
				ans += 4;
				break;
			case 'G' ... 'I':
				ans += 5;
				break;
			case 'J' ... 'L':
				ans += 6;
				break;
			case 'M' ... 'O':
				ans += 7;
				break;
			case 'P' ... 'S':
				ans += 8;
				break;
			case 'T' ... 'V':
				ans += 9;
				break;
			case 'W' ... 'Z':
				ans += 10;
				break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
