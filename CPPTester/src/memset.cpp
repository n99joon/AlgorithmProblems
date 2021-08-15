#include <cstdio>
#include <cstring>

int main(){
	char c,b=' ';
	unsigned char t=0;
	int ans=0,p;
	scanf("%d",&p);
	scanf("%c",&c);
	//printf("p is = %d",p);
	//printf("c is = %c",c);
	int a[26];
	memset(a,0,sizeof(int)*26);
	for(int k=0;k<p;k++){
		b=' ';
		while (scanf("%c",&c) != 0 && c!='\n'){
			//printf("c is = %c\n",c);
			//printf("a is = %d\n",a[c-'a']);
			
			if(a[c-'a']==1 && b!=c) {
				t=1;
				printf("came in \n");
			}
			a[c-'a']=1;
			b=c;
		}
		if (t==0) ans++;
		t=0;
		memset(a,0,sizeof(int)*26);
	}
	printf("%d",ans);
	return 0;
}