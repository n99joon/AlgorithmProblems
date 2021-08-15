#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n;
set<pair<ll, ll>> st;

void go(ll n) {
    ll x = sqrt(n);
    if (x*x != n) x++;
    ll y = x*x-n;
    if (x >= 3) go(x);
    if (y >= 3) go(y);
    auto p = make_pair(x, y);
    if (!st.count(p)) {
        st.insert(p);
        printf("%lld %lld\n", p.first, p.second);
    }
}

int main() {
    scanf("%lld", &n);
    go(n);
	return 0;
}