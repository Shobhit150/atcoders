#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

ll modpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n,k;
    cin >> n >> k;
    long long x = (long long)ceil((sqrtl(1.0L + 8.0L * k) - 1.0L) / 2.0L);
    long long ans = x - (n - 1);

    cout << max(0LL, ans);
}

int main() {
    fastio();

    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
