#include <cstdio>
//#include <cmath>
//using namespace std;
int main(){
	int t,i,sum=0,n,max=-2e9,min=2e9;
	scanf("%d",&t);
	int l[8001]={0};
	n=t;
	while(n--){
		scanf("%d",&i);
		sum+=i;
		l[i+4000]++;
		if(i>max)max=i;
		if(i<min)min=i;
	}
	int cnt=0,frq=-4001,med=-4001,m,ch=0,flag=1;
	for(int p=0;p<8001;p++){
		cnt+=l[p];
		if(cnt>=(t-1)/2+1&&flag) {
			m=p-4000;
			flag=0;
		}
		if(frq<l[p]){
			frq=l[p];
			med=p-4000;
			ch=0;
		} else if (frq==l[p]){
			ch++;
			if(ch==1) med=p-4000;
		}
	}
	printf("%d %d %d %d",sum=sum<0?(int)((float)sum/t-0.5):(int)((float)sum/t+0.5),m,med,max-min);
}