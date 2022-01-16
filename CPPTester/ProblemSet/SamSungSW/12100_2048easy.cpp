#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100000000ULL
#define fi first
#define se second
#define eb 0.000000001
#define mod 1000000003
using namespace std;
int n,mx;
//int brd[10][10];
struct inp{
	vector<vector<int>> bd;
	int cnt;
};

inp psh(inp a, int idx){//idx=1-L 2-R 3-U 4-D
	//left
	//vector<vector<int>> a.bd = a.bd;
	vector<vector<bool>> comb(n,vector<bool>(n,false));
	if(idx==1){
		ffor(i,n){
			ffor(j,n){
				if(a.bd[i][j]==0)continue;
				int k = j-1;
				while(k>=0){
					//if empty cell (continue)
					if(a.bd[i][k]==0){
						if(k==0){
							a.bd[i][k]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						k--;
						continue;
					}
					//if collide with same block
					if(a.bd[i][k]==a.bd[i][j]){
						
						//if not combined yet
						if(comb[i][k]==false){
							a.bd[i][k]*=2;
							a.bd[i][j]=0;
							comb[i][k]=true;
							mx=max(mx,a.bd[i][k]);
						}
						//if combined ardy
						else{
							a.bd[i][k+1]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						break;
					}
					//if collide with other blocks
					//cout << "here" << i << " " << j << " " << k << endl;
					int temp = a.bd[i][j];
					a.bd[i][j]=0;
					a.bd[i][k+1]=temp;
					break;
				}
			}
		}
	}
	//right
	else if(idx==2){
		ffor(i,n){
			for(int j=n-1;j>=0;j--){
				if(a.bd[i][j]==0)continue;
				int k = j+1;
				while(k<n){
					//if empty cell (continue)
					if(a.bd[i][k]==0){
						if(k==n-1){
							a.bd[i][k]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						k++;
						continue;
					}
					//if collide with same block
					if(a.bd[i][k]==a.bd[i][j]){
						//if not combined yet
						if(comb[i][k]==false){
							a.bd[i][k]*=2;
							a.bd[i][j]=0;
							comb[i][k]=true;
							mx=max(mx,a.bd[i][k]);
						}
						//if combined ardy
						else{
							a.bd[i][k-1]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						break;
					}
					//if collide with other blocks
					int temp = a.bd[i][j];
					a.bd[i][j]=0;
					a.bd[i][k-1]=temp;
					break;
				}
			}
		}
	}
	//up
	else if(idx==3){
		ffor(j,n){
			ffor(i,n){
				if(a.bd[i][j]==0)continue;
				int k = i-1;
				while(k>=0){
					//if empty cell (continue)
					if(a.bd[k][j]==0){
						if(k==0){
							a.bd[k][j]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						k--;
						continue;
					}
					//if collide with same block
					if(a.bd[k][j]==a.bd[i][j]){
						//if not combined yet
						if(comb[k][j]==false){
							a.bd[k][j]*=2;
							a.bd[i][j]=0;
							comb[k][j]=true;
							mx=max(mx,a.bd[k][j]);
						}
						//if combined ardy
						else{
							a.bd[k+1][j]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						break;
					}
					//if collide with other blocks
					int temp = a.bd[i][j];
					a.bd[i][j]=0;
					a.bd[k+1][j]=temp;
					break;
				}
			}
		}
	}
	//right
	else if(idx==4){
		ffor(j,n){
			for(int i=n-1;i>=0;i--){
				if(a.bd[i][j]==0)continue;
				int k = i+1;
				while(k<n){
					//if empty cell (continue)
					if(a.bd[k][j]==0){
						if(k==n-1){
							a.bd[k][j]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						k++;
						continue;
					}
					//if collide with same block
					if(a.bd[k][j]==a.bd[i][j]){
						//if not combined yet
						if(comb[k][j]==false){
							a.bd[k][j]*=2;
							a.bd[i][j]=0;
							comb[k][j]=true;
							mx=max(mx,a.bd[k][j]);
						}
						//if combined ardy
						else{
							a.bd[k-1][j]=a.bd[i][j];
							a.bd[i][j]=0;
						}
						break;
					}
					//if collide with other blocks
					int temp = a.bd[i][j];
					a.bd[i][j]=0;
					a.bd[k-1][j]=temp;
					break;
				}
			}
		}
	}
	return {a.bd,a.cnt+1};
}
int main(){
	fastio;
	
	cin >> n;
	
	vector<vector<int>> brd(n,vector<int>(n));
	ffor(i,n){
		ffor(j,n){
			cin >> brd[i][j];
			mx = max(mx,brd[i][j]);
		}
	}
	queue<inp> q;
	q.push({brd,0});
	
	while(!q.empty()){
		inp cur = q.front();
		q.pop();
		if(cur.cnt==5)break;
		forr(i,4){
			inp k = psh(cur,i);
			/*
			//print
			ffor(i,n){
				ffor(j,n){
					cout << k.bd[i][j]<<" ";
				}
				cout << endl;
			}
			cout <<endl;
			//*/
			if(k.cnt<5)q.push(k);
		}
	}
	cout << mx;
}
/*
3
256 8 128
16 0 256
0 8 0
*/