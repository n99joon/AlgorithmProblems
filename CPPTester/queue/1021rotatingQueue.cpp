#include <cstdio>
#include <deque>
using namespace std;
int main(){
	deque<int> dq;
	int n,k,cnt,tgt,ans=0;
	scanf("%d%d",&n,&k);
	//insertion deque
	for(int i=1;i<=n;i++){
		dq.push_back(i);
	}
	while(k--){
		cnt=0;
		scanf("%d",&tgt);
		while(dq.front()!=tgt){
			cnt++;
			dq.push_back(dq.front());
			dq.pop_front();
		}
		ans+=dq.size()-cnt>cnt?cnt:dq.size()-cnt;
		dq.pop_front();
	}
	printf("%d",ans);
}