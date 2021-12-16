#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int x,y,w,h;
	scanf("%d%d%d%d",&x,&y,&w,&h);
	printf("%d",min(min(min(x,y),w-x),h-y));
}