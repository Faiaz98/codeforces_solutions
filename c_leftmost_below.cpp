#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegTree {
    int n;
    vector<ll> t;

    explicit SegTree(int _n) : n(_n), t(4 * n + 4, LLONG_MAX) {}

    void update(int v, int l, int r, int pos, ll val) {
        if (l == r) {
            t[v] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(v*2, l, mid, pos, val);
        else update(v*2+1, mid+1, r, pos, val);
        t[v] = min(t[v*2], t[v*2+1]);
    }

    ll query(int v, int l, int r, int ql, int qr) {
        if (ql > qr) return LLONG_MAX;
        if (ql <= l && r <= qr) return t[v];
        int mid = (l + r) / 2;
        ll res = LLONG_MAX;
        if (ql <= mid) res = min(res, query(v*2, l, mid, ql, qr));
        if (qr > mid) res = min(res, query(v*2+1, mid+1, r, ql, qr));
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> b(n+1);
        for (int i = 1; i <= n; ++i) cin >> b[i];

        SegTree st(n);
        vector<bool> alive(n+1, true);
        for (int i = 1; i <= n; ++i) {
            st.update(1, 1, n, i, b[i]);
        }

        priority_queue<int> pq;
        for (int i = 1; i <= n; ++i) pq.push(i);

        bool ok = true;
        while (!pq.empty()) {
            int i = pq.top();
            pq.pop();
            if (!alive[i]) continue;

            ll bi = b[i];
            ll prefMin = (i > 1) ? st.query(1, 1, n, 1, i-1) : LLONG_MAX;

            if (i > 1 && prefMin * 2 <= bi) {
                ok = false;
                break;
            }

            ll x = (i > 1) ? min(prefMin, bi) : bi;
            bi -= x;

            if (bi > 0) {
                b[i] = bi;
                st.update(1, 1, n, i, bi);
                pq.push(i);
            } else {
                alive[i] = false;
                st.update(1, 1, n, i, LLONG_MAX);
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
