#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MIN(x,y) x>y?y:x
using namespace std;
int mtrx[101][101];
int n,m;

void findDist(){
	for(int i=1;i<=n;i++)
		mtrx[i][i]=0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(mtrx[j][i]!=2e9 && mtrx[i][k]!=2e9 && mtrx[j][i]+mtrx[i][k]<mtrx[j][k])
					mtrx[j][k]=mtrx[j][i]+mtrx[i][k];
			}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mtrx[i][j]==2e9)mtrx[i][j]=0;
			cout << mtrx[i][j] << " ";
		}
			
		cout << endl;
	}
		
}

int main() {
	fastio;
	fill_n(mtrx[0],101*101,(int)2e9);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int st, end, w;
		cin >> st >> end >> w;
		if(mtrx[st][end]>w)mtrx[st][end]=w;
	}
	
	findDist();

}