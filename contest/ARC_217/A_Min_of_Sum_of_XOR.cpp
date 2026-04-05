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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll mod_add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll mod_sub(ll a, ll b) { return (a % MOD - b % MOD + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }

void solve() {
    int n;
    cin >> n;
    if (n == 1) { cout << 1 << "\n"; return; }

    bool one_used = false;
    int i = 2;
    while (i <= n) {
        if (i + 3 <= n) {
            cout << i << " " << i+1 << " " << i+3 << " " << i+2 << " ";
            i += 4;
        } else if (i + 2 <= n) {
            cout << i << " " << i+1 << " " << 1 << " " << i+2 << " ";
            one_used = true;
            i += 3;
        } else if (i + 1 <= n) {
            cout << i << " " << i+1 << " " << 1 << " ";
            one_used = true;
            i += 2;
        } else {
            cout << 1 << " " << i << " ";
            one_used = true;
            i += 1;
        }
    }
    if (!one_used) cout << 1 << " ";
    cout << "\n";
}

int main() {
    fastio

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}