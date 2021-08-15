#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define x first
#define y second
using namespace std;
vector<pair<int,int>> pts;
bool compare(pair<int,int> a, pair<int,int> b){
	return a.y < b.y;
}
int findDV(int s, int e){
	return (s-e)*(s-e);
}
int findD(pair<int,int> s, pair<int,int> e){
	return (s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y);
}
int shortest(int s, int e){
	int temp=2e9;
	//3 2 1
	if(e-s<3){
		for(int i=s;i<e;i++){
			for(int j=i+1;j<=e;j++){
				temp=min(temp,findD(pts[i],pts[j]));
			}
		}
		return temp;
	}
	int mid = (s+e)/2;
	temp = min(shortest(s,mid-1),shortest(mid+1,e));
	
	vector<pair<int,int>> v;
	v.push_back(pts[mid]);
	for(int i=mid-1;i>=s;i--){
		if(findDV(pts[mid].x,pts[i].x)>=temp)
			break;
		v.push_back(pts[i]);
	}
	for(int i=mid+1;i<=e;i++){
		if(findDV(pts[mid].x,pts[i].x)>=temp)
			break;
		v.push_back(pts[i]);
	}
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			if(findDV(v[i].y,v[j].y)>=temp)
				break;
			temp=min(temp,findD(v[i],v[j]));
		}
	}
	return temp;
}

int main(){
	fastio;
	int n;
	cin >> n;
	pts.resize(n);
	for(int i=0;i<n;i++){
		cin >> pts[i].x >> pts[i].y;
	}
	sort(pts.begin(),pts.end());
	cout << shortest(0,n-1) << endl;
}
//https://st-lab.tistory.com/256
//https://blog.naver.com/jinhan814/222095619102
//https://steady-coding.tistory.com/215