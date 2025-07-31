#include <bits/stdc++.h>
using namespace std;

struct Result { bool ok; int l, r; };

Result check(int v, const vector<int>& a, int k) {
    int n = static_cast<int>(a.size());
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + (a[i - 1] >= v ? 1 : -1);

    const long long INF = 4e18;
    long long minVal[2] = {INF, INF};
    int minIdx[2] = {-1, -1};

    for (int r = 1; r <= n; ++r) {
        int idx = r - k;
        if (idx >= 0) {
            int par = idx & 1;
            if (pref[idx] < minVal[par]) {
                minVal[par] = pref[idx];
                minIdx[par] = idx;
            }
        }
        int pr = r & 1;

        if (minIdx[pr] != -1 && pref[r] - minVal[pr] >= 0) {
            return {true, minIdx[pr] + 1, r};
        }
        int popp = pr ^ 1;
        if (minIdx[popp] != -1 && pref[r] - minVal[popp] >= 1) {
            return {true, minIdx[popp] + 1, r};
        }
    }
    return {false, -1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int bestV = 1, bestL = 1, bestR = k;
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            Result res = check(mid, a, k);
            if (res.ok) {
                bestV = mid;
                bestL = res.l;
                bestR = res.r;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << bestV << ' ' << bestL << ' ' << bestR << '\n';
    }
    return 0;
}
