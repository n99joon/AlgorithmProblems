#include <iostream>
using namespace std;
int n[9][9],cnt=0,f,s;
int r=0,prt=0;
pair<int,int> z[81]; // 0 coordinate array

bool val(int x, int y){
	int nx,ny;
	bool arr[10],arrT[10],arrTh[10];
	for(int p=0;p<10;p++){
		arr[p]=0;
		arrT[p]=0;
		arrTh[p]=0;
	}
	/*
	x=(m*3)%9+(m/3);
	y=m;
	*/
	nx=(x/3)*3, ny=(y/3)*3;
		/*
		cout << " x is " << x << "y is " << y << "nx is " << nx << "ny is " << ny << endl; */
	for(int k=0;k<9;k++){

		if(arr[n[k][y]]==1 && n[k][y]!=0) return false;
		else {
			//cout << "reached here " << "n is " << n[k][y] << endl;
			arr[n[k][y]]=1;}
		if(arrT[n[x][k]] && n[x][k]!=0) return false;
		else arrT[n[x][k]]=1;

		if(arrTh[n[nx+k%3][ny+k/3]] && n[nx+k%3][ny+k/3]!=0) return false;
		else arrTh[n[nx+k%3][ny+k/3]]=1;

	}
	return true;
}
	



void solv(int x){
	cout << endl;

	if(x>=r && !prt) {
		
		for(auto& k:n){
				for(auto& l:k)
					cout << l << " ";
				cout << endl;
			}
		
		prt=1;
		return;
	} else if(prt) return;

	
		for(int k=1;k<=9;k++){
			n[z[x].first][z[x].second]=k;
			if(val(z[x].first,z[x].second)){
				solv(x+1);
			}else {
				n[z[x].first][z[x].second]=0;
			}
		}
}

int main(){
	for(int i=0;i<9;i++)
		for(int k=0;k<9;k++){
			cin >> n[i][k];
			if (n[i][k]==0) {
				z[cnt]={i,k};
				cnt++;
			}
		}
	r=cnt;
	solv(0);	
}
	
