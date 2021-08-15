#include <cstdio>
int main(){
	int n,s,m=0,p;
	scanf("%d%d",&n,&s);
	int k[n];
	p=n;
	while(p--){
		scanf("%d",&k[p]);
	}
	for(int a=0;a<n-3;a++)
		for(int b=a+1;b<n-2;b++)
			for(int c=b+1;c<n-1;c++){
				p=k[a]+k[b]+k[c];
				if(p>m&&p<=s) m=p;
			}
	printf("%d",m);
}