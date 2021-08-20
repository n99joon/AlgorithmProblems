#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, i;
	int arr[10001];
	int dp[10001];
	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1]+arr[2];
	
	for(i=3; i<=n; i++)
	{
		dp[i] = max(dp[i-2]+arr[i], max(dp[i-3]+arr[i-1]+arr[i], dp[i-1]));
	}
	
	printf("%d", dp[n]);
}