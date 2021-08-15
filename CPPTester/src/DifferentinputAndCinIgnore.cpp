#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main(){
	cin.tie(NULL);
ios::sync_with_stdio(false);
	string a;
	int t=0;
	while (cin >> a) t++;
	cout << t;
	return 0;
}

/*
while (using formatted input)
{
  cin >> stuff;
}
cin.ignore( numeric_limits<streamsize>::max(), '\n' );

// now use unformatted input
getline( cin, s );
*/

// cin fread<-개빠름 scanf