#include <cstdio>
#define mod 1000000000
int main(){
	int t;
	scanf("%d",&t);
	long long n[t][10]={0,};
	for(int i=1;i<10;i++) n[0][i]=1;
	for(int i=1;i<t;i++){
		n[i][0]=n[i-1][1];
		n[i][9]=n[i-1][8];
		for(int j=1;j<=8;j++){
			n[i][j]=(n[i-1][j+1]+n[i-1][j-1])%mod;
		}
	}
	long long sum=0;
	for(int i:n[t-1]){
		sum+=i;
		sum=sum%mod;
	}
	printf("%lld",sum);
}