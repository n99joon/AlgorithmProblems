#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
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
int n,g,k; 
struct inp{
	int s,l;
};
vector<inp> can;
vector<inp> cant;

inline ull calcGerm(int idx, int day, int o){
	//cant skip
	if(o==0)return cant[idx].s*max(1,day-cant[idx].l);
	else return can[idx].s*max(1,day-can[idx].l);
}

inline ull calcTotal(int day){//day n
	ull ret=0;
	//priority_queue<ull> pq;//maybe to int
	ffor(i,cant.size()){
		ret+=calcGerm(i,day,0);
		if(ret>g)return 2e9;
	}
	/*
	if(day==14){
		for(auto k : cant)cout << k.s << " " << k.l;
		cout <<endl;
		cout << ret<<endl;
	}*/
	//if(ret>g)return 2e9;
	vector<ull> sorted(can.size());
	ffor(i,can.size()){
		//pq.push(calcGerm(i,day,1));
		sorted[i]=calcGerm(i,day,1);
		if(ret>g)return 2e9;
	}
	sort(sorted.begin(),sorted.end(),greater<>());
	
	for(int i=k;i<sorted.size();i++){
		ret+=sorted[i];
	}
	
	/*
	if(day==14){
		cout << ret<<endl;
	}*/
	return ret;
}
int main(){
	clock_t start=clock();
	fastio;
	cin >> n >> g >>k;
	//n == 재료개수
	//g == 세균수 합 최대
	//k == 최대 빼는 개수 
	
	int s,l,o;
	ffor(i,n){
		cin >> s >> l >> o;
		if(o==0)cant.emplace_back((inp){s,l});
		else can.emplace_back((inp){s,l});
		//if(ip[i].o==0)skip++;
	}
	
	int low = 0, high = 2e9,mid;
	while(low<=high){
		mid=(low+high)/2;
		//cout << " calc total : " <<mid << " " <<calcTotal(mid)<<endl;
		if(calcTotal(mid)>g){
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout << high << endl;
	//clock_t end=clock();
	//cout << (double)(end-start);
}