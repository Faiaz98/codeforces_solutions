#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        int coins = 0;
        int step = 0;

        while (!a.empty()) {
            long long maxFreeWeight = (step < 63 ? c >> step : 0);  

            auto it = upper_bound(a.begin(), a.end(), maxFreeWeight);

            if (it != a.begin()) {
                a.erase(prev(it));
            } else {
                a.pop_back();
                coins++;
            }

            step++;
        }

        cout << coins << '\n';
    }

    return 0;
}
