#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        vector<vector<int>> events(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            events[v].push_back(u);
        }

        vector<vector<int>> prefix(n + 1);
        for (int u = 1; u <= n; u++) {
            sort(adj[u].begin(), adj[u].end());
            prefix[u].resize(adj[u].size() + 1, 0);
            for (int j = 0; j < adj[u].size(); j++) {
                prefix[u][j + 1] = prefix[u][j] ^ adj[u][j];
            }
        }

        int q;
        cin >> q;
        vector<tuple<int, int, int, int>> queries;
        for (int i = 0; i < q; i++) {
            int l, r, k;
            cin >> l >> r >> k;
            queries.emplace_back(r, l, k, i);
        }

        sort(queries.begin(), queries.end());
        vector<int> currentF(n + 1, 0);
        vector<int> ans(q, -1);

        int idx = 0;
        vector<int> values;
        values.reserve(n);
        for (int r_val = 1; r_val <= n; r_val++) {
            for (int u : events[r_val]) {
                currentF[u] ^= r_val;
                currentF[r_val] ^= u;
            }

            while (idx < q && get<0>(queries[idx]) == r_val) {
                int l = get<1>(queries[idx]);
                int k = get<2>(queries[idx]);
                int q_idx = get<3>(queries[idx]);
                idx++;

                values.clear();
                for (int u = l; u <= r_val; u++) {
                    auto& a = adj[u];
                    auto it = lower_bound(a.begin(), a.end(), l);
                    int pos = it - a.begin();
                    int xor_val = prefix[u][pos];
                    int final_val = currentF[u] ^ xor_val;
                    values.push_back(final_val);
                }
                nth_element(values.begin(), values.begin() + k - 1, values.end());
                ans[q_idx] = values[k - 1];
            }
        }

        for (int i = 0; i < q; i++) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}