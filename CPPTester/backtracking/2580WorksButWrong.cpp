#include <iostream>
using namespace std;

bool w[9][9],l[9][9],s[9][9];
int n[9][9],wc[9],lc[9],sc[9],cnt=0,x;
pair<int,int> z[81];

void solv(){
	if(cnt==0)return;
	for(int a=0;a<9;a++){
		//look for empty in width
		if(wc[a]==8){
			for(int b=0;b<9;b++){
				//found empty number
				if(w[a][b]==0){
					w[a][b]=1;
					wc[a]=9;
					cnt--;
					for(int h=0;h<81;h++){
						if(z[h].first==a){
							n[z[h].first][z[h].second]=b+1;
							l[z[h].second][b]=1;
							lc[z[h].second]++;
							s[a/3+(int)(z[h].second/3)*3][b]=1;
							sc[a/3+(int)(z[h].second/3)*3]++;
							z[h]={-1,-1};
							break;
						}
					}
				}
			}
		}
		
		//look for empty in length
		if(lc[a]==8){
			for(int b=0;b<9;b++){
				//found empty number
				if(l[a][b]==0){
					l[a][b]=1;
					lc[a]=9;
					cnt--;
					for(int h=0;h<81;h++){
						if(z[h].second==a){
							n[z[h].first][z[h].second]=b+1;
							z[h]={-1,-1};
							w[z[h].first][b]=1;
							wc[z[h].first]++;
							s[z[h].first/3+(int)(a/3)*3][b]=1;
							sc[z[h].first/3+(int)(a/3)*3]++;
							break;
						}
					}
				}
			}
		}
		
		//look for empty in square
		if(sc[a]==8){
			for(int b=0;b<9;b++){
				//found empty number
				if(s[a][b]==0){
					s[a][b]=1;
					sc[a]=9;
					cnt--;
					for(int h=0;h<81;h++){
						int f = z[h].first; 
						int sec = z[h].second;
						
						if(f/3+(int)(sec/3)*3==a){
							n[f][sec]=b+1;
							z[h]={-1,-1};
							w[f][b]=1;
							wc[f]++;
							l[sec][b]=1;
							lc[sec]++;
							
							break;
						}
					}
				}
			}
		}	
	}
}
int main(){
	for(int i=0;i<9;i++)
		for(int p=0;p<9;p++){
			cin >> x;
			n[i][p]=x;
			if(x==0){
				z[cnt]={i,p};
				cnt++;
			}else{
				//width
				w[i][x-1]=1;
				wc[i]++;
				//length
				l[p][x-1]=1;
				lc[p]++;
				//square
				if(i<3){
					if(p<3) {s[0][x-1]=1; sc[0]++;}
					else if(p<6) {s[3][x-1]=1; sc[3]++;}
					else {s[6][x-1]=1; sc[6]++;}
				}else if(i<6){
					if(p<3) {s[1][x-1]=1; sc[1]++;}
					else if(p<6) {s[4][x-1]=1; sc[4]++;}
					else {s[7][x-1]=1; sc[7]++;}
				} else {
					if(p<3) {s[8][x-1]=1; sc[2]++;}
					else if(p<6) {s[8][x-1]=1; sc[5]++;}
					else {s[8][x-1]=1; sc[8]++;}
				}
			}
		}

	solv();
	for(auto& o:n){
		for(auto& g:o)
			cout << g << " ";
		cout << "\n";
	}
}