#include <cstdio>

int main(){
	int n,cur=0,in,pos=-1,retPos=0,flag=1;
	scanf("%d",&n);
	int s1[n+1];
	char ret[4*n+1];
	for(int i=0;i<n;i++){
		scanf("%d",&in);
		if(in<=cur){
			if(s1[pos]!=in){
				printf("NO\n");
				flag=0;
				break;
			} else {
				ret[retPos++]='-';
				ret[retPos++]='\n';
				pos--;
			}
		} else{
			while(cur<in){
				s1[++pos]=++cur;
				ret[retPos++]='+';
				ret[retPos++]='\n';
			}
			ret[retPos++]='-';
			ret[retPos++]='\n';
			pos--;
		}
		/*
		printf("pos = %d\n",pos);
		printf("Retpos = %d\n",retPos);
		printf("s1[pos] = %d\n",s1[pos]);
		printf("cur = %d\n",cur);
		*/
	}
	ret[--retPos]='\0';
	printf("%s",ret);
	/*
	if(flag){
		for(char k:ret){
			if(k!='-'&&k!='+') break;
			printf("%c\n",k);
		}
	}
	*/
}