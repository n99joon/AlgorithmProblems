#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct block {
	int idx,val;
};

int main(){
	int n,k=0;
	scanf("%d",&n);
	block st[n+1];
	int ret[n];
	memset(ret,-1,sizeof(ret));
	//printf("%ld",sizeof(ret));
	for(int i=0;i<n;i++){
		block bl;
		scanf("%d",&bl.val);
		bl.idx=i;
		
		if(k==0){
				st[0]={bl.idx,bl.val};
				k++;
		}else{
			for(int p=k-1;p>=0;p--){
					if(st[p].val<bl.val){
						ret[st[p].idx]=bl.val;
						k--;
					} else break;
				
			}
			st[k].idx=bl.idx;
			st[k++].val=bl.val;
		}
		/*
		printf("k=%d\n",k);
		for(auto& m: st){
			cout << m.idx << " " << m.val << "\n";
		}
		*/
		
	}
	for(int l : ret){
		printf("%d ",l);
	}
	
}