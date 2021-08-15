#include <cstdio>
#include <cmath>
#define ll unsigned long long
#define mod 1000000007ll
using namespace std;


void mCopy(ll **a, ll **b){
	for(ll i=0;i<2;i++)
		for(ll j=0;j<2;j++)
			a[i][j]=b[i][j];
}

ll** mProd(ll **a,ll **b,int size){
	ll** temp=new ll*[2];
	for(int i=0;i<2;i++) temp[i]=new ll[2];
	for(int t=0;t<size;t++)
		for(int k=0;k<size;k++)
			temp[t][k]=0;
	for(int k=0;k<size;k++){
		for(int m=0;m<size;m++){
			for(int l=0;l<size;l++){
				temp[k][m]=(temp[k][m]+(a[k][l]*b[l][m])%mod)%mod;
			}
			//printf("%d ",r);
			//r=0;
		}
	}
	return temp;
}

void pow(ll ex,int size,ll ** ar){
	ll** temp=new ll*[2];
	for(int i=0;i<2;i++) temp[i]=new ll[2];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			if(i==j)temp[i][j]=1;
			else temp[i][j]=0;
	
	for(;ex;ex/=2){
		if(ex&1){
			temp=mProd(temp,ar,size);
		}
		ar=mProd(ar,ar,size);
	}
	for(int t=0;t<size;t++){
		for(int k=0;k<size;k++)
			printf("%lld ",temp[t][k]);
		printf("\n");
	}
	
	printf("\n%lld",temp[0][1]);
		
}
int main(){
	
	ll** ar=new ll*[2];
	for(int i=0;i<2;i++) ar[i]=new ll[2];
	ar[0][0]=1;
	ar[0][1]=1;
	ar[1][0]=1;
	ar[1][1]=0;

	ll n;
	scanf("%lld",&n);
	pow(n,2,ar);
}