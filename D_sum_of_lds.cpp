#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> p(n + 2, 0);
        for (int i = 1; i <= n; ++i) cin >> p[i];

        vector<int> nextGreater(n + 2, n + 1);
        stack<int> st;

        for (int i = 1; i <= n; ++i) {
            while (!st.empty() && p[st.top()] < p[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += (ll)i * (nextGreater[i] - i);
        }

        cout << ans << "\n";
    }

    return 0;
}
