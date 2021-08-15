#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
#define uint unsigned int
using namespace std;
int n,k;
vector<int> a;

//RadixSort / Time = Best, avg, worst=O(n*k), Space = O(n+k) but not in place
void radixSort(){
	int cnt[4][256]={0,},x,s,temp;
	vector<int> tempV(a.size());
	//count # of occurences
	for(int i=0;i<a.size();i++){
		x=a[i];
		for(int j=0;j<4;j++){
			cnt[j][(uint)(x&0xff)]++;
			x>>=8;
		}
	}
	
	//change to indices
	for(int i=0;i<4;i++){
		s=0;
		for(int j=0;j<256;j++){
			temp=s;
			s+=cnt[i][j];
			cnt[i][j]=temp;
		}
	}
	
	//do radix sort
	for(int i=0;i<4;i++){
		for(int j=0;j<a.size();j++){
			x=a[j];
			s=(int)((x>>(i<<3))&0xff);
			tempV[cnt[i][s]++]=x;
		}
		a=tempV;
	}
	

}

int main() {
	fastio;
	cin >> n;
	int t;
	for(int i=1;i<=n;i++){
		cin >> t;
		a.push_back(t);
	}
	clock_t start=clock();
	radixSort();
	clock_t end=clock();
	cout << (double)(end-start) << endl;
	for(auto i=a.begin();i!=a.end();i++){
		cout << *i << " ";
	}
}
//https://yabmoons.tistory.com/248
//https://tibyte.kr/292
//https://www.python2.net/questions-1074827.htm