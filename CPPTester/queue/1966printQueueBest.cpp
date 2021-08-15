#include<stdio.h>
#include<algorithm>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,M,A[101],c=0;
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;++i)scanf("%d",A+i);
		int t=0;
		for(int h=9;h>=0;--h){
			int u=t;
			//queue implementation with modulo&마지막 숫자 위치 저장
			for(int i=t;i<N+t;++i){
				if(A[i%N]==h){
					++c;
					u=i%N;
					if(i%N==M)printf("%d\n",c);
				}
			}
			t=u;
		}
	}
}