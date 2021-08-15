#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int t,l;
	int p=0;
	scanf("%d%d",&t,&l);
	int a[t];
	int ans[l];
	for(int k=0;k<t;k++){
		a[k]=k+1;
		//if(k<l) ans[l]=k+1;
	}
	
	do{
		p=1;
		for(int k=0;k<l;k++){
			if(a[k]!=ans[k]) p=0;
			ans[k]=a[k];
		}
		if(!p) {
			for(int k=0;k<l;k++)
				cout << a[k] << " ";
			cout << "\n";
		}
		
	} while(next_permutation(a,a+t));
}