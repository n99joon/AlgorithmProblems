#include <cstdio>
#include <queue>
using namespace std;

int main(){
	priority_queue<int> pq;
	queue<int> q;
	int n,k,t,in,tgt;
	scanf("%d",&t);
	while(t--){
		int cnt=0;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&in);
			if(i==k){
				tgt=in;
				pq.push(tgt);
				in=0;
			}
			else pq.push(in);
			q.push(in);
		}
		/*
			for(int i=0;i<q.size();i++){
			printf("%d ",q.front());
			q.push(q.front());
			q.pop();
			}
		printf("\n");
		*/
		while(1){
			if(q.front()==0){
				if(tgt>=pq.top()){
					cnt++;
					printf("%d\n",cnt);
					break;
				}
				else {
					q.push(0);
					q.pop();
				}
			}
			else if(q.front()!=pq.top()){
				q.push(q.front());
				q.pop();
			} else {
				cnt++;
				q.pop();
				pq.pop();
			}
			/*
			for(int i=0;i<q.size();i++){
			printf("%d ",q.front());
			q.push(q.front());
			q.pop();
			
			}
			printf("\n");
			*/
		}
		q=queue<int>();
		pq=priority_queue<int>();
	}
}