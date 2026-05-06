#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {
            if(wt[i - 1] <= w)
                K[i][w] = max(K[i - 1][w],
                              val[i - 1] + K[i - 1][w - wt[i - 1]]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout << "\nMaximum Profit: " << K[n][W] << endl;

    // Find selected items
    int w = W;
    cout << "Selected items (0-based index): ";
    for(int i = n; i > 0 && w > 0; i--) {
        if(K[i][w] != K[i - 1][w]) {
            cout << i - 1 << " ";
            w -= wt[i - 1];
        }
    }

    return 0;
}
