#include <iostream>
#include <cstring>
#include <cmath>
//WRONG  -> faster if we find the # of prime till n for every n and do 2n - n ;
using namespace std;
int main(){
	int b=246912;
	int ans[b+1];
	memset(ans,0,(b+1)*sizeof(int));
	ans[1]=1;
	for(int k=2;k<=sqrt(b);k++){
		if(!ans[k]){
			for(int p=k*k;p<=b;p+=k){
				ans[p]=1;
			}
		}
	}
	cin>>b;
	while(b!=0){
		int cnt = 0;
		for(int t=b+1;t<=2*b;t++){
			if(!ans[t]) cnt++;
		}
		printf("%d\n",cnt);
		cin>>b;
	}
	return 0;
}

/*
#include <cstdio>
#include <algorithm>
using namespace std;

int isPrime[123460*2];

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    fill_n(isPrime, 123460*2, 1);
    for(int i=2; i<123460*2; i++){
        if(isPrime[i]){
            for(int j=i*2; j<123460*2; j+=i)
                isPrime[j] = 0;
        }
    }
    isPrime[1] = false;
    for(int i=1; i<123460*2-1; i++){
        isPrime[i+1] += isPrime[i];
    }
    while(1){
        scanf("%d", &n);
        if(n==0) break;
        printf("%d\n", isPrime[2*n] - isPrime[n]);
    }
    return 0;
}
*/