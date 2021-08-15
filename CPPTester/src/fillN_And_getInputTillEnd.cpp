#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int s, cnt=0;
	int arr[26];
	fill_n(arr,26,-1);
	while ((s = fgetc(stdin)) != EOF && s != '\n'){
		if(arr[s-'a']==-1) arr[s-'a']=cnt;
		cnt++;
	}
	for ( int a : arr) printf("%d ", a);
	return 0;
}
