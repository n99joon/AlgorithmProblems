#include <cstdio>
#include <algorithm>
using namespace std;

struct p{
	int x,y;
};

bool comp(p a,p b){
	if(a.x>b.x) return 0;
	else if (a.x==b.x && a.y>b.y) return 0;
	else return 1;
}
int main(){
	int t,s;
	scanf("%d",&t);
	p pts[t];
	s=t;
	while(t--){
		scanf("%d%d",&pts[t].x,&pts[t].y);
	}
	sort(pts,pts+s,comp);
	for(int l=0;l<s;l++){
		printf("%d %d ",pts[l].x,pts[l].y);
	}
}
/*
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	pair<int, int> v[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v, v+n);
	for(int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << '\n';
	return 0;
}
*/