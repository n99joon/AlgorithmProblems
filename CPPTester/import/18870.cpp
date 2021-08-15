#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int t;
	cin >> t;
	vector<int> v(t);
	
	for(int i=0;i<t;i++){
		cin >> v[i];
	}
	
	//벡터 복사
	vector<int> cv(v);
	sort(cv.begin(), cv.end());
	
	//중복제거
	cv.erase(unique(cv.begin(),cv.end()),cv.end());
	//unique 함수는 기존 벡터에서 중복 제거.
	//리턴값은 중복을 제외한 나머지의 시작점.
	for(int i=0;i<t;i++){
		auto it=lower_bound(cv.begin(),cv.end(),v[i]);
		cout << it - cv.begin() << ' ';
	}
}