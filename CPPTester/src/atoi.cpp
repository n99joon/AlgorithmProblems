#include <cstdio>
#include <stdlib.h>
#include <cstdlib>

int main(){
	char a[4];
	char b[4];
	char spc;
	scanf("%1c",&a[2]);
	scanf("%1c",&a[1]);
	scanf("%1c",&a[0]);
	scanf("%1c",&spc);
	scanf("%1c",&b[2]);
	scanf("%1c",&b[1]);
	scanf("%1c",&b[0]);
	int t = (atoi(a)>atoi(b))?atoi(a):atoi(b);
	printf("%d", t);

	
	return 0;
}

/*
헤더파일 : <stdlib.h> <cstdlib>



int atoi (const char* cStr);

double atof (const char* cStr);

long int atol (const char* cStr);



cStr이라고 적은 이유는 C스타일의 문자열이라는 것을 강조하기 위해서 변수명을 그렇게 지정했습니다.

만약에 C++의 string을 이용했다면 c_str() 함수를 이용해서 C스타일의 문자열로 변환해서 이용해야합니다.



출처: https://blockdmask.tistory.com/331 [개발자 지망생]
*/