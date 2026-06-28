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
    vector<pair<int,int>> taka(n);
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        taka[i] = {b,a};
    }

    sort(taka.begin(), taka.end());

    vector<int> suff(n);
    suff[n-1] = taka[n-1].second;

    for(int i=n-2;i>=0;i--) {
        suff[i] = max(suff[i+1], taka[i].second);
    }

    int queries;
    cin >> queries;

    for(int i=0;i<queries;i++) {
        int q;
        cin >> q;
        auto it = lower_bound(taka.begin(), taka.end(), make_pair(q + 1, INT_MIN));
        
        int idx = it - taka.begin();
        cout << suff[idx] << '\n';
    }
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