#include <iostream>
#include <cstring>
using namespace std;
int cnt=0,n;
void solv(int k, int ** board){
	//for debug
	/*
	cout << "k is " << k << "\n";
	for(int i=0;i<n;i++){
		for(int x=0;x<n;x++){
			cout << board[i][x] << " ";
		}
		cout << "\n";
	}
	*/
	if(k==n){
		cnt++;
		return;
	}
	for(int p=0;p<n;p++){
		if(board[k][p]==0){
			for(int i=0;i<n;i++){
				board[k][i]+=1;
				board[i][p]+=1;
				if(k-i>=0 && p-i>=0) board[k-i][p-i]+=1;
				if(k+i<n && p-i>=0) board[k+i][p-i]+=1;
				if(k-i>=0 && p+i<n) board[k-i][p+i]+=1;
				if(k+i<n && p+i<n) board[k+i][p+i]+=1;
			}
			board[k][p]-=5;
			solv(k+1,board);
			for(int i=0;i<n;i++){
				board[k][i]-=1;
				board[i][p]-=1;
				if(k-i>=0 && p-i>=0) board[k-i][p-i]-=1;
				if(k+i<n && p-i>=0) board[k+i][p-i]-=1;
				if(k-i>=0 && p+i<n) board[k-i][p+i]-=1;
				if(k+i<n && p+i<n) board[k+i][p+i]-=1;
			}
			board[k][p]+=5;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n;
	//pair<int,int> p[n];
	int **board;
	board = new int*[n];
	for(int i=0;i<n;i++) board[i]=new int[n];
	//memset(board,0,sizeof(int)*n*n);
	solv(0,board);
	cout << cnt;
}