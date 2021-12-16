#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int main(){
	cin.sync_with_stdio(false);
    cin.tie(0);
	
	int n,k;
	cin >> n;
	
	string a;
	deque<int> q;
	
	while(n--){
		cin >> a;
		if(a=="push_front"){
			cin >> k;
			q.push_front(k);
		} else if(a=="push_back"){
			cin >> k;
			q.push_back(k);
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
		} else if(a=="pop_front"){
			if(q.empty()) cout << -1 << "\n";
			else{
				cout << q.front() << "\n";
				q.pop_front();
			}
		} else if(a=="pop_back"){
			if(q.empty()) cout << -1 << "\n";
			else{
				cout << q.back() << "\n";
				q.pop_back();
			}
		}
	}
}