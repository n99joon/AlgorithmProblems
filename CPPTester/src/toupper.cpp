#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	int arr[26]={0};
	char s, ans;
	int max=0;
	while ((s=fgetc(stdin)) != EOF && s != '\n'){
		arr[toupper(s)-'A']++;
		if (arr[toupper(s)-'A'] > max){
			ans = toupper(s);
			max = arr[toupper(s)-'A'];
		} else if (arr[toupper(s)-'A'] == max){
			ans ='?';
		}
	}
	printf("%c",ans);
}
