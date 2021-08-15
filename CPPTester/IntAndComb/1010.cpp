#include <cstdio>
#define NK_MAX 31

int main(){
	int t;
	long long N,K;
	scanf("%d",&t);
	while(t--){
	scanf("%lld%lld",&K,&N);
	long long dp[NK_MAX][NK_MAX] = { 0 };
    for(long long n_row = 1; n_row <= N; n_row++){
        for (long long k_col = 0; k_col <= n_row; k_col++) {
            if (n_row == k_col || k_col == 0) {
                dp[n_row][k_col] = 1; continue;
            }
            dp[n_row][k_col] = (dp[n_row - 1][k_col] + dp[n_row - 1][k_col - 1]);
        }
    }
    printf("%lld\n", dp[N][K]);
	}
}