#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
char ans[3073][6300];
void printStar(int n,int x, int y){//3 2 0
	if(n==3){
		ans[y][x]='*';//1 (0,2)
		ans[y+1][x-1]='*'; //2
		ans[y+1][x+1]='*';
		ans[y+2][x-2]='*'; //3
		ans[y+2][x-1]='*';
		ans[y+2][x]='*';
		ans[y+2][x+1]='*';
		ans[y+2][x+2]='*';
	}else{
		printStar(n/2,x,y);
		printStar(n/2,x-n/2,y+n/2);
		printStar(n/2,x+n/2,y+n/2);
	}
}


int main() {
	fastio;
	int i;
	cin >> i;
	fill_n(&ans[0][0],6300*i,' ');
	printStar(i,i-1,0);
	for(int k=0;k<i;k++){
		for(int j=0;j<2*i;j++){
			cout << ans[k][j];
		}
		cout << endl;
	}
}