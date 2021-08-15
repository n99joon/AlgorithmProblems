#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);	
	int n,k,x;
	string s;
	cin >> n;
	deque<int> dq;
	while(n--){
		int forb=0; //0=front, 1=back
		int flag=0;
		cin >> s >> k;
		cin.ignore(256,'[');
		for(int i=0;i<k;i++){			
			cin >> x;
			if(i!=k-1)cin.ignore(256,',');
			dq.push_back(x);
		}
		cin.ignore(256,']');
		for(int i=0;i<s.length();i++){
			if(s[i]=='R'){
				if(i!=s.length()-1 && s[i+1]=='R'){
					i++;
					continue;
				}
				else{
					forb^=1;
				}
			}else{
				if(dq.size()==0){
					flag=1;
					break;
				}else if(!forb){
					dq.pop_front();
				}else dq.pop_back();
			}
		}
		if(!flag){
			cout << "[";
		int size=dq.size();
		if(!forb){
			for(int i=0;i<size;i++){
				cout << dq.front();
				dq.pop_front();
				if(i!=size-1)cout<<",";
			}
		}else{
			for(int i=0;i<size;i++){
				cout << dq.back();
				dq.pop_back();
				if(i!=size-1)cout<<",";
			}
		}
		cout << "]\n";
		}else{
			cout << "error\n";
		}
		
		dq=deque<int>();
	}
}