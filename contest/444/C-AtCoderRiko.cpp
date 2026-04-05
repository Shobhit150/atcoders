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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int mini = arr[0];
    int maxi = arr[n-1];

    unordered_set<int> set1;

    for(int i=0;i<n;i++) {
        int L = mini + arr[i];
        if(L >= maxi) set1.insert(L);
    }

    set1.insert(maxi);

    vector<int> ans;

    for(int L : set1) {

        int l = 0, r = n - 1;
        bool ok = true;

        while(l <= r) {

            if(arr[l] + arr[r] == L) {
                l++;
                r--;
            }
            else if(arr[r] == L) {
                r--;
            }
            else {
                ok = false;
                break;
            }
        }

        if(ok) ans.push_back(L);
    }

    sort(ans.begin(), ans.end());

    for(int x : ans) cout << x << " ";
    cout << "\n";
    
}

int main() {
    fastio();

    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
