#include <iostream>
using namespace std;

int binomialCoefficient(int n, int k) {
    // Base cases
    if (k == 0 || k == n)
        return 1;

    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main() {
    int n, k;
    cout << "Enter n (total items): ";
    cin >> n;
    cout << "Enter k (items to choose): ";
    cin >> k;

    if (k > n || n < 0 || k < 0) {
        cout << "Invalid input! Ensure that 0 <= k <= n." << endl;
        return 1;
    }

    int result = binomialCoefficient(n, k);
    cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << result << endl;

    return 0;
}
