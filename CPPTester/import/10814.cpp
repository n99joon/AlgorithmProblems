#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct mem{
	int age,no;
	string name;
};

bool comp(struct mem x,struct mem y){
	if (x.age == y.age) return x.no<y.no;
	else return x.age<y.age;
}

int main(){
	int t,k,l;
	scanf("%d",&t);
	vector<struct mem> a;
	int cnt=0;
	l=t;
	
	while(t--){
		string s;
		cin >> k >> s;
		cnt++;
		mem p;
		p.age=k;
		p.name=s;
		p.no=cnt;
		
		a.push_back(p);
	}
	
	sort(a.begin(),a.end(),comp);
	
	for(int i=0;i<a.size();i++){
		cout << a[i].age << "\n"<< a[i].name << "\n";
	}
}