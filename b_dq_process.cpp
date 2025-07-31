#include <bits/stdc++.h>
using namespace std;

bool safe_with(const deque<int>& last, int x) {
    if (last.size() < 4) return true;
    int a0 = last[0], a1 = last[1], a2 = last[2], a3 = last[3];
    if (a0 < a1 && a1 < a2 && a2 < a3 && a3 < x) return false;
    if (a0 > a1 && a1 > a2 && a2 > a3 && a3 > x) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int& x : p) cin >> x;

        int l = 0, r = n - 1;
        deque<int> last; 
        string res;
        res.reserve(n);

        while (l <= r) {
            bool okL = safe_with(last, p[l]);
            bool okR = safe_with(last, p[r]);
            char pick = '?';

            if (okL && !okR) {
                pick = 'L';
            } else if (!okL && okR) {
                pick = 'R';
            } else if (okL && okR) {
                deque<int> Dl = last;
                if ((int)Dl.size() == 4) Dl.pop_front();
                Dl.push_back(p[l]);
                bool futureL = true;
                if (l + 1 <= r) {
                    bool f1 = safe_with(Dl, p[l + 1]);
                    bool f2 = safe_with(Dl, p[r]);
                    futureL = f1 || f2;
                }

                deque<int> Dr = last;
                if ((int)Dr.size() == 4) Dr.pop_front();
                Dr.push_back(p[r]);
                bool futureR = true;
                if (l <= r - 1) {
                    bool f1 = safe_with(Dr, p[l]);
                    bool f2 = safe_with(Dr, p[r - 1]);
                    futureR = f1 || f2;
                }

                if (futureL && !futureR) pick = 'L';
                else if (!futureL && futureR) pick = 'R';
                else pick = 'L'; 
            } else {
                pick = 'L';
            }

            if (pick == 'L') {
                if ((int)last.size() == 4) last.pop_front();
                last.push_back(p[l++]);
                res.push_back('L');
            } else {
                if ((int)last.size() == 4) last.pop_front();
                last.push_back(p[r--]);
                res.push_back('R');
            }
        }

        cout << res << "\n";
    }

    return 0;
}
