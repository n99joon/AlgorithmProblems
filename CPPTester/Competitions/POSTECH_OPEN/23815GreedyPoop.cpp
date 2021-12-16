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
struct inp {
	int round;
	int cur; // current # of ppl
	int used; // 1 = x used , 0 = used
};

inline int doCalc(char a, int b, int cur){
	if(a=='+'){
		return cur+b;
	}if(a=='*'){
		return cur*b;
	}if(a=='-'){
		return cur-b;
	}
	return cur/b;
}
inline bool isBad(char a){
	if(a=='-' || a=='/')return true;
	return false;
}
inline int findMax(char a, char aa, int b, int bb, int cur){
	if(isBad(a) && !isBad(aa)){
		return doCalc(aa,bb,cur);
	}else if(!isBad(a) && isBad(aa)){
		return doCalc(a,b,cur);
	}
	int ar, aar;
	ar = doCalc(a,b,cur);
	aar = doCalc(aa,bb,cur);
	return max(ar,aar);
}

int main(){
	//fastio;
	int n;
	scanf("%d",&n);
	int num = 1;
	queue<inp> q;
	q.push({n,1,1});
	
	int ans =1, mx =-1;
	while(n--){
	   int nxt;
	   char a,aa;
	   int b,bb;
	   scanf(" %c%d %c%d",&a,&b,&aa,&bb);
		//cout<<a << b << aa << bb;
		if(q.empty()){
			printf("ddong game");
			return 0;
		}
	   
	   if(mx!=-1)mx = findMax(a,aa,b,bb,mx);
	   while(!q.empty() && q.front().round!=n){
		   int cur = q.front().cur;
		   int usd = q.front().used;
		   int k = findMax(a,aa,b,bb,cur);
		   q.pop();
		   if(k>0){
			   q.push({n,k,usd});
			   if(n==0)ans=max(ans,k);
		   }
		   
		   if(isBad(a) && isBad(aa)){
			   if(cur>mx){
				   mx=cur;
			       //if(n==0)ans=max(ans,cur);
			   }
		   }
	   }
	}
	//if(q.empty())cout<<"ddong game";
	//else{
		printf("%d", max(ans,mx));
	//}
	return 0;
}