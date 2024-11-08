// you have a binary string s of length n. in one operation you can select a substring of s and reverse it. find min number
// of operations required to sort binary string

#include <bits/stdc++.h>
using namespace std;

int sort_binary(string num) {
    int count = 0;
    char last = '-';
    for (int i = 0; i < num.length(); i++) {
        if (num[i] != last) {
            count++;
            last = num[i];
        }
    }

    return (count + 1) / 2;
}

int main() {
    string num;
    cout << "Enter binary string: ";
    cin >> num;
    
    int res = sort_binary(num);
    cout << "Minimum operations to sort the binary string: " << res << endl;
    
    return 0;
}
