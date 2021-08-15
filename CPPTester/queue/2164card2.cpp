#include <cstdio>
#include <cmath>
int main(){
	int n,k,e=0,ans=1,ex=0,o=0; //e=0 = even/ o=0 = even;
	scanf("%d",&n);
	k=n;
	while(k>1){
		//전에가 짝
		if(e) o=o^1;
		e=k%2;
		if(!o){
			ans+=pow(2,ex);
			k/=2; //홀이든 짝이든 /2
		} else{ //전에가 홀
			if(k%2==1) k=k/2+1;
			else k=k/2;	
		}
		
		ex++;
		//printf("%d %d %d\n",ans,e,k);
	}
	printf("%d",ans);
}