#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int t,a,b,c,d,e,f;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		float dist=sqrt((a-d)*(a-d)+(b-e)*(b-e));
		
	    
		if(a==d&&b==e&&c==f&&c!=0)printf("-1 ");
		else if(max(c,f)==min(c,f)+dist||dist==c+f)printf("1 ");
		else if(dist>c+f||max(c,f)>min(c,f)+dist)printf("0 ");
		else printf("2 ");
	}
}