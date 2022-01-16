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
#define mx (1e8*8-1)
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		ll oa,ob,oc;
		cin >> oa >>ob >>oc;
		ll a = oa;
		ll b = ob;
		ll c = oc;
		int x1=1,y1=1,x2,y2,x3,y3;
		if(a>c)swap(a,c);
		if(b>c)swap(b,c);
		if(b>a)swap(a,b);//a>b,c>a
		if(c>mx*2 || a+b < c || a+b+c > mx*4){cout<<-1<<endl;continue;}
		
		//p2 calc
		if(a<=mx){
			x2=1+a;
			y2=1;
		}else{
			x2=1+mx;
			y2=1-mx+a;
		}
		//p3 calc
		//net total
		ll net = c-a;
		if(net%2 != b%2){cout<<-1<<endl;continue;}
		ll plus = (b-net)/2 + net;
		ll minus = b - plus;
		//p3 plus calc
		if(y2+plus <=mx){
			y3 = y2+plus;
			//minus calc
			x3 = x2-minus;
		}
		else{
			cout << -1 << endl;
			continue;
		}
		
		
		//calc original order
		ll x[3] = {x1,x2,x3};
		ll y[3] = {y1,y2,y3};
		while(1){
			if(abs(x[1]-x[0])+abs(y[1]-y[0])==oa)
				if(abs(x[2]-x[1])+abs(y[2]-y[1])==ob)
					if(abs(x[2]-x[0])+abs(y[2]-y[0])==oc){
						cout << x[0] << " " << y[0] <<" " << x[1] <<" " << y[1] <<" " << x[2] <<" " << y[2]<<endl;
						break;
					}
			swap(x[0],x[1]);
			swap(y[0],y[1]);
			if(abs(x[1]-x[0])+abs(y[1]-y[0])==oa)
				if(abs(x[2]-x[1])+abs(y[2]-y[1])==ob)
					if(abs(x[2]-x[0])+abs(y[2]-y[0])==oc){
						cout << x[0] << " " << y[0] <<" " << x[1] <<" " << y[1] <<" " << x[2] <<" " << y[2]<<endl;
						break;
					}
			swap(x[1],x[2]);
			swap(y[1],y[2]);
		}
		
	}
}
