#include <iostream>

using namespace std;
int n,m,a[7]; 

void f(int x){
	//printf("x and y is %d %d\n",x,y);
	if(x==m) {
		for(int k=0;k<m;k++){
			cout << a[k] << " ";
		}
		cout << "\n";
		return;
	}else{
		for(int k=1;k<=n;k++){
			a[x]=k;
			f(x+1);
		}
	}
}


int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n >> m;
	f(0);
}