#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int h;
    int w;
    cin >> h >> w;
    vector<vector<char>> vec(h+1, vector<char>(w+1,'.'));
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin >> vec[i+1][j+1];
        }
    }
    int top = 1;
    while (top <= h) {
        bool ok = false;
        for (int j = 1; j <= w; j++)
            if (vec[top][j] == '#') ok = true;
        if (ok) break;
        top++;
    }

    int bottom = h;
    while (bottom >= 1) {
        bool ok = false;
        for (int j = 1; j <= w; j++)
            if (vec[bottom][j] == '#') ok = true;
        if (ok) break;
        bottom--;
    }

    int left = 1;
    while (left <= w) {
        bool ok = false;
        for (int i = top; i <= bottom; i++)
            if (vec[i][left] == '#') ok = true;
        if (ok) break;
        left++;
    }

    int right = w;
    while (right >= 1) {
        bool ok = false;
        for (int i = top; i <= bottom; i++)
            if (vec[i][right] == '#') ok = true;
        if (ok) break;
        right--;
    }

    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++)
            cout << vec[i][j];
        cout << '\n';
    }
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}