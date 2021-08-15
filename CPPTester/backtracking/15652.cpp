#include <iostream>

using namespace std;
int n,m,a[8]; 

void f(int x,int y){
	//printf("x and y is %d %d\n",x,y);
	if(x==m) {
		for(int k=0;k<m;k++){
			cout << a[k] << " ";
		}
		cout << "\n";
		return;
	}else{
		for(int k=y;k<=n;k++){
			a[x]=k;
			f(x+1,k);
		}
	}
}


int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n >> m;
	f(0,1);
}