#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int t,l;
	int p=0,f=0;
	scanf("%d%d",&t,&l);
	int a[t];
	int ans[l];
	for(int k=0;k<t;k++){
		a[k]=k+1;
		//if(k<l) ans[l]=k+1;
	}
	
	do{
		p=1;
		f=1;
		for(int k=0;k<l;k++){
			if(a[k]!=ans[k])p=0;
			if(k>0) if(a[k]<a[k-1])f=0;
			ans[k]=a[k];
		}
		if(!p&&f) {
			for(int k=0;k<l;k++)
				cout << a[k] << " ";
			cout << "\n";
		}
		
	} while(next_permutation(a,a+t));
}
/*
#include <stdio.h>
int n,m,a[9];
bool b[9],c=true;
void f(int p,int l)
{
	if(p==m)
	{
		for(int i=0;i<m;i++) printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(int i=l;i<=n;i++)
		if(b[i]==false)
		{
			b[i]=true;
			a[p]=i;
			f(p+1,i+1);
			b[i]=false;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	f(0,1);
}
*/