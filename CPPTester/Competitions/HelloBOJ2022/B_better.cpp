#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll n, m, k, ans;
const ll mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i, j, temp=0;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        if((a+b<c)||(b+c<a)||(c+a<b)||(a+b+c)%2)
        {
            cout<<"-1\n";
            continue;
        }
        // cout<<"YES\n";
        ll s=(a+b+c)/2;
        ll x=s/2, y=s-x;
        if(min({a, b, c})==a)
        {
            cout<<c-y+1<<' '<<y+1<<' ';
            cout<<x+1<<' '<<b-x+1<<' ';
            cout<<"1 1\n";
        }
        else if(min({a, b, c})==b)
        {
            cout<<"1 1 ";
            cout<<x+1<<' '<<a-x+1<<' ';
            cout<<c-y+1<<' '<<y+1<<'\n';
        }
        else if(min({a, b, c})==c)
        {
            cout<<x+1<<' '<<a-x+1<<' ';
            cout<<"1 1 ";
            cout<<b-y+1<<' '<<y+1<<'\n';
        }
    }
}
