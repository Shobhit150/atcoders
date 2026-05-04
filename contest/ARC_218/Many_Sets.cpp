#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int MOD = 998244353;
const ll INF = 1e18;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll mod_add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll mod_sub(ll a, ll b) { return (a % MOD - b % MOD + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }

ll power(ll a , ll b) { // log(n)
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<pair<int,int>>> mp;
    for(int i=0;i<n;i++) {
        unordered_map<int,int> tmp;
        for(int j=0;j<m;j++) {
            int x;
            cin >> x;
            tmp[x]++;
        }
        for(auto &p: tmp) {
            mp[p.first].push_back({i, p.second});
        }
    }

    long long total = power(m, n);
    ll inv_m = power(m, MOD - 2);

    long long ans = 0;

    for(auto &[num, vec]: mp) {
        ll without = total;
        for (auto &[row, cnt] : vec) {
            without = without * (m - cnt) % MOD;
            without = without * inv_m % MOD;
        }
        ll with = (total - without + MOD) % MOD;
        ans = (ans + with)%MOD;
    }

    cout << ans << "\n";


}

int main() {
    fastio

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}