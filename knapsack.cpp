#include <iostream>
using namespace std;

int main() {
    int n, W;
    int wt[100], val[100], dp[101][1001];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights of items: ";
    for (int i = 1; i <= n; i++)
        cin >> wt[i];

    cout << "Enter values of items: ";
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i] <= w)
                dp[i][w] = max(val[i] + dp[i-1][w-wt[i]],
                               dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum value = " << dp[n][W];

    return 0;
}
