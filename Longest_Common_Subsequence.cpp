#include <bits/stdc++.h>
using namespace std;

// Function to compute the length of LCS
int LCS_length(vector<vector<int>>& arr, string a, string b) {
    int m = a.length();
    int n = b.length();

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                arr[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            } else {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    return arr[m][n];
}

// Function to find the LCS sequence
string LCS(vector<vector<int>>& arr, string a, string b) {
    string lcs;
    int m = a.length();
    int n = b.length();
    int i = m, j = n;

    // Backtracking to find the LCS sequence
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        } else if (arr[i - 1][j] > arr[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());  // Reverse to get the correct order
    return lcs;
}

int main() {
    string a, b;
    cout << "Enter first string: ";
    getline(cin, a);
    cout << "Enter second string: ";
    getline(cin, b);

    vector<vector<int>> arr(a.length() + 1, vector<int>(b.length() + 1));

    cout << "Length of LCS is: " << LCS_length(arr, a, b) << endl;
    cout << "Longest common subsequence: " << LCS(arr, a, b) << endl;

    return 0;
}
