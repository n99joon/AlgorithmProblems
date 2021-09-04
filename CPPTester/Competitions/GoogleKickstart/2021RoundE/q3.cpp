#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;
char brd[1001][1001];
int r,c;
bool isVal(int x, int y){
	return (x>=0 && y>=0 && x < c && y<r && brd[x][y]!='#');
}

int main() {
	fastio;
	int tc;
	cin >> tc;
	for(int i=1;i<=tc;i++){
		cin >> r >> c;
		ll ans=0;
		for(int y=0;y<r;y++){
			for(int x=0;x<c;x++){
				cin >> brd[x][y];
			}
		}
		int flag=1;
		while(flag){
			flag=0;
			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){
					if(brd[x][y]=='.' || brd[x][y]=='#')continue;
					int xs=x,xe=x;
					int ys=y,ye=y;
					//horizontal
					while(isVal(--xs,y)){}
					while(isVal(++xe,y)){}
					xs++;
					xe--;
					int xo = xe-(x-xs);
					if(xo!=x && brd[xo][y]=='.'){
						flag=1;
						brd[xo][y]=brd[x][y];
						ans++;
					}
					
					while(isVal(x,--ys)){}
					while(isVal(x,++ye)){}
					ys++;
					ye--;
					int yo = ye-(y-ys);
					if(yo!=y && brd[x][yo]=='.'){
						flag=1;
						brd[x][yo]=brd[x][y];
						ans++;
					}
				}
			}
		}
		cout << "Case #" << i << ": "<<ans<<endl;
		for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){
					cout << brd[x][y];
			}
			cout << endl;
		}
	}
}
