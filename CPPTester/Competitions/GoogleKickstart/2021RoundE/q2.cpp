#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ll long long
using namespace std;


int main() {
	fastio;
	int tc;
	cin >> tc;
	for(int i=1;i<=tc;i++){
		int r,c,k;
		ll ans=0;
		cin >> r >> c >> k;
		int ro,co,rt,ct;
		cin >> ro >> co >> rt >> ct;
		
		int f=0; //0 = ver , 1 = hor
		//cut the first two side
		int l = min(min(rt,r-ro+1),min(ct,c-co+1));
		if(l==min(rt,r-ro+1)){
			f=1;
		}
		int hLen = rt-ro+1;
		int vLen = ct-co+1;
		//cut all the sides
		ans+=ceil((double)l/k);
		ans+=ceil((double)vLen/k);
		//cout << "vLen is " << vLen << "k is " << k << "ceil is " << ceil((double)vLen/k) << endl;
		ans+=ceil((double)hLen/k);
		if(f)ans+=ceil((double)vLen/k);
		else ans+=ceil((double)hLen/k);
		
		//cout << "sides  " << ans << endl;
		
		if(vLen < hLen){//if ver len is less then hor len
			ans += ceil((double)vLen/k)*(hLen-1);
			ans += (hLen)*(vLen-1);
		}else{
			ans += ceil((double)hLen/k)*(vLen-1);
			ans += (vLen)*(hLen-1);
		}
		
		//cout << "sides  " << ans << endl;
		if(ro==1){
			ans -= ceil((double)hLen/k);
			
		}
		if(rt==r){
			ans -= ceil((double)vLen/k);
			
		}
		if(co==1){
			ans -= ceil((double)vLen/k);
			
		}
		if(ct==c){
			ans -= ceil((double)hLen/k);
			
		}
		
		cout << "Case #" << i << ": " << ans << endl;
	}
	
}
