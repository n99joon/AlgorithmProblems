#include <stdio.h>
#include <iostream>
#define ABS(val)	((val) < 0 ? -(val): (val))
#define mi(a, b)	((a) < (b) ? (a) : (b))
#define MAX(a, b)	((a) > (b) ? (a) : (b))

using namespace std;

int N = 0;
int S[20][20] = { 0, };
int All = 0;
int R[20] = { 0, };
int C[20] = { 0, };

int mi = 1 << 31 - 1;


void func(int depth, int count, int sum)
{
	cout << "depth is " << depth << "count is "<<count<<"sum is " << sum << endl;
	if (count == N / 2)
	{
		mi = mi(mi, ABS(sum));
		return;
	}

	if (depth == N)
		return;

	func(depth + 1, count + 1, sum - R[depth] - C[depth]);
	func(depth + 1, count, sum);
}

int main(){
	fscanf(stdin, "%d\n", &N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			fscanf(stdin, "%d", S[i] + j );
			All += S[i][j];
			R[i] += S[i][j];
			C[j] += S[i][j];
		}		
	}
	for(auto& k:R) cout << "R is " << k << endl;
	for(auto& k:C) cout << "C is " << k << endl;
	cout << "Total sum is " << All << endl;
	func(1, 1, All - R[0] - C[0]);
	printf("%d\n", mi);

	return 0;
}