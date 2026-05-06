#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    vector<int> files(n);

    cout << "Enter file sizes:\n";
    for(int i = 0; i < n; i++)
        cin >> files[i];

    // Step 1: Sort file sizes (Greedy choice)
    sort(files.begin(), files.end());

    int totalTime = 0, cumulative = 0;

    // Step 2: Calculate MRT
    for(int i = 0; i < n; i++) {
        cumulative += files[i];
        totalTime += cumulative;
    }

    double MRT = (double)totalTime / n;

    cout << "\nOptimal Order: ";
    for(int i = 0; i < n; i++)
        cout << files[i] << " ";

    cout << "\nMean Retrieval Time: " << MRT << endl;

    return 0;
}
