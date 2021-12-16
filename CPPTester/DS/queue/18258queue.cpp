#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
	cin.sync_with_stdio(false);
    cin.tie(0);
	
	int n,k;
	cin >> n;
	
	string a;
	queue<int> q;
	
	while(n--){
		cin >> a;
		if(a=="push"){
			cin >> k;
			q.push(k);
		} else if(a=="front"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		} else if(a=="back"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		} else if(a=="empty"){
			cout << q.empty() << "\n";
		} else if(a=="size"){
			cout << q.size() << "\n";
		} else {
			if(q.empty()) cout << -1 << "\n";
			else{
				cout << q.front() << "\n";
				q.pop();
			}
		}
	}
}