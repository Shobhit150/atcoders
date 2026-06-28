#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll X, vector<pair<ll,ll>>& seg, int K) {
    int N = seg.size();

    vector<ll> R(N);
    for(int i = 0; i < N; i++) R[i] = seg[i].second;

    vector<int> dp(N, 1);
    vector<int> pref(N);

    int best = 0;

    for(int i = 0; i < N; i++) {
        ll need = seg[i].first - X;

        int pos = upper_bound(R.begin(), R.begin() + i, need) - R.begin() - 1;

        if(pos >= 0)
            dp[i] = pref[pos] + 1;

        pref[i] = dp[i];
        if(i) pref[i] = max(pref[i], pref[i - 1]);

        best = max(best, dp[i]);
    }

    return best >= K;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> p(n);

    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(),
         [](const auto& a, const auto& b) {
             return a.second < b.second;
         });

    if(!check(0, p, k)) {
        cout << -1 << '\n';
        return;
    }

    ll lo = 0;
    ll hi = 1000000000LL;
    ll ans = 0;

    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;

        if(check(mid, p, k)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}