#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total += a[i];
        }

        if (s < total) {
            sort(a.begin(), a.end());
            for (int i = 0; i < n; ++i) {
                cout << a[i];
                if (i < n - 1) cout << " ";
            }
            cout << '\n';
        } else if (s == total) {
            cout << -1 << '\n';
        } else {
            int d = s - total;
            if (d == 1) {
                int cnt0 = 0, cnt1 = 0, cnt2 = 0;
                for (int x : a) {
                    if (x == 0) cnt0++;
                    else if (x == 1) cnt1++;
                    else if (x == 2) cnt2++;
                }
                vector<int> out;
                for (int i = 0; i < cnt0; ++i) out.push_back(0);
                for (int i = 0; i < cnt2; ++i) out.push_back(2);
                for (int i = 0; i < cnt1; ++i) out.push_back(1);
                for (int i = 0; i < n; ++i) {
                    cout << out[i];
                    if (i < n - 1) cout << " ";
                }
                cout << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}