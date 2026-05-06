#include <iostream>
#include <vector>
using namespace std;

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Build DP table
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Reconstruct LCS
    int i = m, j = n;
    string lcs = "";

    while(i > 0 && j > 0) {
        if(X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--; j--;
        }
        else if(L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "\nLength of LCS: " << L[m][n] << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}