#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &a, vector<int> &b, vector<int> &c) {
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += b[i];
    }
    
    for(int i=0;i<n-1;i++) {
        
        if(a[i]+1 == a[i+1]) {
            ans += c[a[i]-1];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i];
    }
    solve(n, a, b, c);

    return 0;
}
