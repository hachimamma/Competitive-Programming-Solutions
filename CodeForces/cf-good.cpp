#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p[] = {2, 3, 5, 7};
const int np = 4;

ll ct_mul(ll n, ll prod) {
    return n / prod;
}

ll incexc(ll n) {
    ll total = n;
    for (int mask = 1; mask < (1 << np); ++mask) {
        ll prod = 1;
        int bits = __builtin_popcount(mask);
        for (int i = 0; i < np; ++i) {
            if (mask & (1 << i)) {
                prod *= p[i];
                if (prod > n) {
                    prod = 0;
                    break;
                }
            }
        }
        if (prod == 0) continue;
        if (bits%2 == 1) {
            total -= ct_mul(n, prod);
        } else {
            total += ct_mul(n, prod);
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll gr = incexc(r);
        ll gl = incexc(l - 1);
        cout << gr - gl << '\n';
    }
    return 0;
}