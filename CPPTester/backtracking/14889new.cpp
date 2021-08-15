#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

#define abs(val)	((val) < 0 ? -(val): (val))
using namespace std;

int n[20][20],t,mi=1e9;
vector<int> y;
vector<int> no;



int solv(int idx,bool yes,int sum){
	if(idx>=t/2-1) return sum;
	for(int i=1;i<t/2-idx;i++){
		//cout << "idx and idx+i is " << t/2-idx << endl;
			if(yes){
				sum+=n[y[idx]][y[idx+i]];
			} else{
				sum+=n[no[idx]][no[idx+i]];
			}
		}
	
	return solv(idx+1,yes,sum);
}

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
	int team[t]={0};
	for(int i=0;i<t/2;i++){
		team[t-i-1]=1;
	}
	/*
	cout << "team is" ;
		for(auto& i:team) cout << i << " " ;
		cout << endl;
		*/
	//solv();
	
	int cnt=0, tfact=1, thfact=1;
	for(int l=1;l<=t;l++){
		tfact*=l;
		if(l<=t/2) thfact*=l;
	}
	//cout << "tfact is " << tfact << " thfact is "<< thfact<<endl;
	do{
		for(int i=0;i<t;i++){
			if(team[i]) y.push_back(i);
			else no.push_back(i);
		}
		/*
		 cout << "team yes is" ;
		for(auto& i:y) cout << i << " " ;
		cout << endl;
		cout << "team no is" ;
		for(auto& i:no) cout << i << " " ;
		cout << endl;
		*/
		int h=solv(0,0,0);
		int t=solv(0,1,0);
		if(abs(h-t)<mi) mi = abs(h-t);
		
		//erase vector
		y.clear();
		no.clear();
		cnt++;
		
	} while(next_permutation(team,team+t));
	
	printf("%d",mi);
	/*
	cout<<endl;
	for(auto& i:n){
		for(auto&k : i)
			cout << k << " ";
		cout<<endl;
		
	}*/
}
