#include <cstdio>
#include <vector>
using namespace std;

int main(){
	long n,i,sum=0;
	vector<long> s1;
	scanf("%ld",&n);
	while(n--){
		scanf("%ld",&i);
		if(i==0){
			sum-=s1.back();
			s1.pop_back();
		}
		else{
			sum+=i;
			s1.push_back(i);
		}
	}
	printf("%ld",sum);
}