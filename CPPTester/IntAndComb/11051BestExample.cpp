#include <stdio.h>
int pow(int base, int exp, int mod) {
	int res = 1;
	for (; exp; exp >>= 1, base = (base * base) % mod) {
		if (exp & 1) {
			res = (res * base) % mod;
		}
	}
	return res;
}
int main() {
	int k, n;
	scanf("%d%d", &n, &k);
	if (k == 0) { printf("1"); }
	else {
		int temp = 1;
		int m = 1;
		while (temp <= 10007 && k>=1) {
			temp = temp * n / m;
			k--;
			m++;
			n--;
		}
		while ( k>= 1) {
			temp = (((temp *n)%10007)* pow(m,10005,10007)) % 10007;
			k--;
			m++;
			n--;
		}
		printf("%d", temp);
	}
}