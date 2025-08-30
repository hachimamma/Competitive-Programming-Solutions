#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int x = a[j-1];
        int R = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                R++;
            }
        }
        if (R == 0) {
            cout << "YES\n";
        } else {
            if (k >= 2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}