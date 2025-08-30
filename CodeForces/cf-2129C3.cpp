#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> p;

void precompute() {
    ll sum = 0;
    for (int i = 1; i <= 130; i++) {
        ll tri = (ll)i * (i + 1) / 2;
        if (tri > sum) {
            p.push_back(i);
            sum += tri;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int group_size = p.size();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> base;
        for (int i = 0; i < n; i++) {
            base.push_back(i);
        }
        auto doask = [&](vector<int> indices) -> int {
            cout << "? " << indices.size();
            for (int idx : indices) {
                cout << " " << idx + 1;
            }
            cout << endl;
            cout.flush();
            int res;
            cin >> res;
            return res;
        };
        int indr;
        int low = 0, high = n;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            vector<int> q;
            for (int i = 0; i <= mid; i++) {
                q.push_back(i);
            }
            int res = doask(q);
            if (res == 0) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (high == n) {
            indr = n - 1;
        } else {
            indr = high;
        }
        vector<char> ans(n, ')');
        for (int start = 0; start < n; start += group_size) {
            vector<int> q;
            for (int j = 0; j < group_size; j++) {
                int pos = start + j;
                if (pos >= n) break;
                for (int k = 0; k < p[j]; k++) {
                    q.push_back(pos);
                    q.push_back(indr);
                }
                q.push_back(indr);
            }
            int res = doask(q);
            for (int j = min(group_size - 1, n - start - 1); j >= 0; j--) {
                ll tri = (ll)p[j] * (p[j] + 1) / 2;
                if (res >= tri) {
                    ans[start + j] = '(';
                    res -= tri;
                }
            }
        }
        cout << "! ";
        for (char c : ans) {
            cout << c;
        }
        cout << endl;
        cout.flush();
    }
    return 0;
}