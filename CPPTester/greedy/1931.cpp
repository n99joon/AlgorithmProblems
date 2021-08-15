#include <cstdio>
#include <algorithm>
using namespace std;
struct m{
	long x,y;
};
bool comp(m k,m j){
	if(k.y==j.y) return k.x<j.x;
	return k.y<j.y;
}
int main(){
	long t,ans=0,cur=0;
	scanf("%d",&t);
	m a[t];
	for(int i=0;i<t;i++){
		scanf("%ld%ld",&a[i].x,&a[i].y);
	}
	
	sort(a,a+t,comp);
	printf("\n");
	for(auto& i:a){
		printf("%ld %ld\n",i.x,i.y);
	}
	for(int i=0;i<t;i++){
		if (a[i].x>=cur) {
			ans++;
			cur=a[i].y;
		}
	}
	printf("%d",ans);
}