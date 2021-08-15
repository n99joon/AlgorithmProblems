#include <cstdio>
long p[6]={0,},mi;
int main(){
	int t,i[3],cnt=0;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d%d",&i[0],&i[1],&i[2]);
		if(cnt%3==0){
			p[0]+=i[0];
			p[1]+=i[0];
			p[2]+=i[1];
			p[3]+=i[1];
			p[4]+=i[2];
			p[5]+=i[2];
		}
		else if(cnt%3==1){
			p[0]+=i[1];
			p[1]+=i[2];
			p[2]+=i[0];
			p[3]+=i[2];
			p[4]+=i[0];
			p[5]+=i[1];
		}
		else{
			p[0]+=i[2];
			p[1]+=i[1];
			p[2]+=i[2];
			p[3]+=i[0];
			p[4]+=i[0];
			p[5]+=i[1];
		}
		cnt++;
	}
	mi=p[0];
	for(int k=1;k<6;k++){
		if(p[k]<mi) mi=p[k];
	}
	printf("%ld",mi);
}