#include <cstdio>
#include <queue>
using namespace std;
int main(){
	queue<int> q;
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	printf("<");
	while(q.size()){
		for(int i=1;i<k;i++){
			q.push(q.front());
			q.pop();
		}
		if(q.size()==1)printf("%d",q.front());
		else printf("%d, ",q.front());
		q.pop();
	}
	printf(">");
}