#include <cstdio>
#include <algorithm>
using namespace std;
int GCD(int x, int y){
	if(x%y==0)return y;
	return GCD(y,x%y);
}
int main(){
	int t;
	int ans[501];
	scanf("%d",&t);
	int n[t];
	for(int i=0;i<t;i++)scanf("%d",&n[i]);
	sort(n,n+t);
	int g=n[1]-n[0];
	for(int i=2;i<t;i++){
		g=GCD(g,n[i]-n[i-1]);
	}
	int cnt=0;
	for(int i=2;i*i<=g;i++){
		if(g%i==0){
			ans[cnt++]=i;
			if(i*i!=g)ans[cnt++]=g/i;
		}
	}
	ans[cnt++]=g;
	sort(ans,ans+cnt);
	for(int i=0;i<cnt;i++)printf("%d ",ans[i]);
	
}