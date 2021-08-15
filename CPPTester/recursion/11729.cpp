#include <cstdio>
#include <cmath>
using namespace std;
void hanoi(int n,int s,int e){
	if(n==1){
		printf("%d %d\n",s,e);
		return;
	}
	hanoi(n-1,s,6-s-e);
	printf("%d %d\n",s,e);
	hanoi(n-1,6-s-e,e);
}
int main(){
	int t;
	scanf("%d",&t);
	printf("%d\n",(int)pow(2,t)-1);
	hanoi(t,1,3);
}