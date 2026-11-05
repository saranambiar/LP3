#include <bits/stdc++.h>
using namespace std;

int main() {
    int wt[]  = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    const int n = 4;
    const int W = 7;

    // dp[i][w] = best value using first i items with capacity w
    int dp[n + 1][W + 1] = {};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // option 1: skip item i
            dp[i][w] = dp[i - 1][w];

            // option 2: take item i (only if it fits)
            if (wt[i - 1] <= w) {
                int take = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                dp[i][w] = max(dp[i][w], take);
            }
        }
    }

    // print the table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }
    cout << "Max value = " << dp[n][W] << endl;

    // find which items were taken (walk backwards)
    int w = W;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Took item " << i << " (wt=" << wt[i - 1] << ", val=" << val[i - 1] << ")" << endl;
            w = w - wt[i - 1];
        }
    }

    cout << "\nTime O(n * W), Space O(n * W)" << endl;
    return 0;
}
