#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define db double
#define pii pair<int,int>
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define forr(i, x) for (int (i) = 1; (i) <=(x) ; ++(i))
#define MAX 100000000ULL
#define fi first
#define se second
#define eb 0.000000001
#define mod 1000000003
using namespace std;

struct LCA{
	vector<int> spt; // sparse table
	int n,mx;
	
	LCA(int n){
		//this->mx = (int)log2(n)+1;
		spt = vector<int>(n+1,0);
		this->n = n;
	}
	
	void addEdge(int ch, int prt){
		spt[ch]=prt;
	}
	/*
	void calc(){
		forr(i,mx){
			forr(j,n){
				spt[j][i]=spt[spt[j][i-1]][i-1];
			}
		}
	}*/
	int getLevel(int k){
		if(spt[k]==0)return 0;
		return 1+getLevel(spt[k]);
	}
	int findParent(int x, int i){//return ith ancestor of x
		if(i==0)return x;
		return findParent(spt[x],i-1);
	}
	int search(int a, int b){ // a is deeper
		int al = getLevel(a);
		int bl = getLevel(b);
		if(bl>al){
			swap(a,b);
			swap(al,bl);
		}
		
		a = findParent(a,al-bl);
		if(a==b) return a;
		//cout << a << " " <<b << endl;
		while(a!=b){
			a=spt[a];
			b=spt[b];
			/*
			for(int i=mx-1;i>=0;i--){
				if(spt[a][i]==spt[b][i])continue;
				a = spt[a][i];
				b = spt[b][i];
			}
			*/
		}
		return a;
		//return spt[a][0];
	}
};

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n,a,b;
		cin >> n;
		LCA * root = new LCA(n);
		ffor(i,n-1){
			cin >> a >> b;
			root->addEdge(b,a);
		}
		//root->calc();
		cin >> a >> b;
		cout << root->search(a,b) << endl;
	}
}
//https://kibbomi.tistory.com/201
//https://m.blog.naver.com/kks227/220820773477
//https://exponential-e.tistory.com/34