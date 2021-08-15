#include <cstdio>
#include <cstring>
#define ll unsigned long long
using namespace std;


void mCopy(int **a, int **b){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			a[i][j]=b[i][j];
}

int** mProd(int **a,int **b,int size){
	int** temp=new int*[5];
	for(int i=0;i<5;i++) temp[i]=new int[5];
	for(int t=0;t<size;t++)
		for(int k=0;k<size;k++)
			temp[t][k]=0;
	for(int k=0;k<size;k++){
		for(int m=0;m<size;m++){
			for(int l=0;l<size;l++){
				temp[k][m]=(temp[k][m]+(a[k][l]*b[l][m])%1000)%1000;
			}
			//printf("%d ",r);
			//r=0;
		}
	}
	return temp;
}

void pow(ll ex,int size,int ** ar){
	int** temp=new int*[5];
	for(int i=0;i<5;i++) temp[i]=new int[5];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
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
			printf("%d ",temp[t][k]);
		printf("\n");
	}
		
}
int main(){
	
	int** ar=new int*[5];
	for(int i=0;i<5;i++) ar[i]=new int[5];

	int n,t;
	ll k;
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&t);
			ar[i][j]=t;
		}
	
	pow(k,n,ar);
}