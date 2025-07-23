#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4 != 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<int> a;
        int sum_even = 0, sum_odd = 0;
        for (int i = 1; i <= n/2; i++) {
            a.push_back(2 * i);
            sum_even += 2 * i;
        }
        for (int i = 1; i < n/2; i++) {
            a.push_back(2 * i - 1);
            sum_odd += 2 * i - 1;
        }
        a.push_back(sum_even - sum_odd);
        for (int x : a) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
