#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    const int MAX_TEMP = 200000;

    vector<int> dp(MAX_TEMP + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        dp[l]++;
        dp[r + 1]--;
    }

    vector<int> prefix(MAX_TEMP + 1, 0);

    int OA = 0;

    for (int temp = 1; temp <= MAX_TEMP; temp++) {
        OA += dp[temp];

        prefix[temp] = prefix[temp - 1];

        if (OA >= k)
            prefix[temp]++;

    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
    }

    return 0;
}