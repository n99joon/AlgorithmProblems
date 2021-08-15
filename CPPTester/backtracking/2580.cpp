#include <iostream>
using namespace std;

int n[9][9],cnt=0,x,y;
pair<int,int> z[81];

void solv(int ){
	if(cnt==0) {
		for(int i=0;i<9;i++)
		for(int p=0;p<9;p++){
			cout << n[i][p] << " ";
		}
		cout << "\n";
	}
	else {
		
	}
}
int main(){
	for(int i=0;i<9;i++)
		for(int p=0;p<9;p++){
			cin >> n[i][p];
			if(n[i][p]==0){
				z[cnt]={i,p};
				cnt++;
			}
		}
	solv();
}