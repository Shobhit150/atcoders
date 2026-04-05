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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    ll ans = 0;

    for(int i=1;i<n;i++) {
    
        if(a[i] > a[i-1]+1) {
        
            ans += (a[i] - a[i-1]-1);
        
            a[i] = a[i-1]+1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i+1] + 1) {
            ans += (a[i] - a[i+1] - 1);
            a[i] = a[i+1] + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    fastio();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
