#include<bits/stdc++.h>
using namespace std;

void lorder(int i, int n) {
    if (i > n) {
        return;
    }
    cout << i << " ";
    for (int j = 0; j <= 9; j++) {
        if (10 * i + j > n) {
            return;
        }
        lorder(10 * i + j, n);
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        lorder(i, n);
    }
    cout << endl;
}
