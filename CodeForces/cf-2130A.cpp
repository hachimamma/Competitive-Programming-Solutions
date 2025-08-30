#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long total = 0;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            total += x;
            if (x == 0) zeros++;
        }
        total += zeros;
        cout << total << '\n';
    }
    return 0;
}