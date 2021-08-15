#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define swap(x,y) int temp=x;x=y;y=temp;
using namespace std;
int n,k;
vector<int> a;

//RadixSort / Time = Best, avg, worst=O(n*k), Space = O(n+k) but not in place
void radixSort(){
	vector<queue<int>> q(10);
	for(int i=0;i<=k;i++){
		for(int j=0;j<n;j++){
			int t;
			int m=(int)(a[j]%(int)pow(10,i+1))/(int)pow(10,i);
			q[m].push(a[j]);
		}
		int idx=0;
		for(int p=0;p<10;p++){
			while(!q[p].empty()){
				a[idx++]=q[p].front();
				q[p].pop();
			}
		}
		q=vector<queue<int>>(10);
	}
}

int main() {
	fastio;
	cin >> n;
	int t,max=0;
	for(int i=1;i<=n;i++){
		cin >> t;
		if(t>max)max=t;
		a.push_back(t);
	}
	clock_t start=clock();
	k=(int)log10(max);
	radixSort();
	clock_t end=clock();
	cout << (double)(end-start);
	for(auto i=a.begin();i!=a.end();i++){
		cout << *i << " ";
	}
}
//https://yabmoons.tistory.com/248
//https://tibyte.kr/292