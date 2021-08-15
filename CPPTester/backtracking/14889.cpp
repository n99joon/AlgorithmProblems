#include <cstdio>
#include <cmath>
int n[20][20],t,min=0;
/*
void solv(int x){
	if(x>=t/2){
		if()
	}
}
*/
int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		for(int j=0;j<t;j++){
			scanf("%d",&n[i][j]);
			if(n[j][i]!=0){
				n[i][j]+=n[j][i];
				n[j][i]=n[i][j];
			}
		}
	int team[t];
	for(int i=0;i<t/2;i++){
		team[t-i-1]=1;
	}
	//solv();
	vector<int> y,n;
	do{
		for(int i=0;i<t;i++){
			if(team[i]) y.push_back(team[i]);
			else n.push_back(team[i]);
		}
		for(int i=0;i<t/2;i++){
			
		}
	} while(next_permutation(team,team+t));
}