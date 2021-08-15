#include <iostream>
using namespace std;
int main(){
	string a,b,temp;
	cin >> a >> b;
	short l,s,u=0;
	char x,y; 
	if(b.length()>a.length()){
		temp=a;
		a=b;
		b=temp;
	}
	l=a.length(); s=b.length();
	//addition
	for(short t=0;t<l;t++){
		//add small to large
		if(t<s){
			x=(int)b[s-t-1]-'0';
			y=(int)a[l-t-1]-'0';
			a[l-t-1]=(char)((x+y+u)%10+'0');
			u=(x+y+u)/10;
		}//only large
		else{
			x=(int)a[l-t-1]-'0';
			a[l-t-1]=(char)((x+u)%10+'0');
			u=(x+u)/10;
		}
	}
	if(u)printf("1");
	for(char k:a) printf("%c",k);
}

/*
a[t]=to_string((atoi(b[t])+atoi(a[t]))%10);
			a[t+1]=to_string((atoi(a[t+1])+(atoi(b[t])+atoi(a[t]))/10));
*/

/*
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
	string a,b;
	cin >> a >> b;
	long t=a.length(),p; int k=0,u=0,m;
	if(a.length()>b.length()){
		k=1;
		t=b.length();
	}
	p=t;
	while(t--){
		if(k){
			m=(int)a[t]-'0';
			a[t]=(((int)b[t]-'0'+(int)a[t]-'0'+u)%10)+'0';
			if(((int)b[t]-'0'+m+u)/10) u=1;
			else u=0;
		} else{
			m=(int)b[t]-'0';
			b[t]=(((int)a[t]-'0'+(int)b[t]-'0'+u)%10)+'0';
			if(((int)a[t]-'0'+m+u)/10) u=1;
			else u=0;
		}
	}
	
	if(a.length()==b.length() && u==1) printf("%d",1);
	if(k) for (char c : a) printf("%c",c);
	else for(char c:b)printf("%c",c);
}
*/