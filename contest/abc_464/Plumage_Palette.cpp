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

bool comp(vector<vector<int>>&a, vector<vector<int>>&b) {
    return a[1] < b[1];
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> changes(m + 1);
    vector<int> freq(n + 1, 0);
    int destinct = 0;
    for(int i=0;i<n;i++) {
        int a,d,b;
        cin >> a >> d >> b;

        freq[a]++;
        changes[d].push_back({a, b});
    }

    for (int i = 1; i <= n; i++)
        if (freq[i] != 0)
            destinct++;

    for(int i=1;i<=m;i++) {
        for (auto [oldColor, newColor] : changes[i]) {
            freq[oldColor]--;
            if (freq[oldColor] == 0)
                destinct--;

            if (freq[newColor] == 0)
                destinct++;
            freq[newColor]++;
        }
        cout << destinct << '\n';
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