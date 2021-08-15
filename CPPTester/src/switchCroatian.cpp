#include <cstdio>

int main(){
	char a,b=' ',c=' ';
	int ans=0;
	while (scanf("%c",&a)!=0 && a!='\n'){
		ans++;
		switch(c){
			case 'd':
				if(b=='z' && a=='=' || b=='-') ans--;
				break;
			case 'c':
				if(b=='=' || b=='-') ans--;
				break;
			case 'l': 
			case 'n':
				if(b=='j') ans--;
				break;
			case 'z': 
			case 's':
				if(b=='=') ans--;
				break;
		}
		c=b;
		b=a;
		//printf("ans is = %d",ans);
	}
	a=' ';
	//printf("c is = %c",c);
	//printf("b is = %c",b);
	//printf("a is = %c",a);
	switch(c){
		case 'd':
			if(b=='z' && a=='=' || b=='-') ans--;
			break;
		case 'c':
			if(b=='=' || b=='-') ans--;
			break;
		case 'l': 
		case 'n':
			if(b=='j') ans--;
			break;
		case 'z': 
		case 's':
			if(b=='=') ans--;
			break;
	}
	
	printf("%d",ans);
}