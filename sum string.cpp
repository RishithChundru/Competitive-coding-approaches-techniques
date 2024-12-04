#include <bits/stdc++.h>
using namespace std;

string addStrings(const string &num1, const string &num2) {
    string result = "";
    int carry = 0, i = num1.length() - 1, j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool isSumStringUtil(const string &str, int start, const string &num1, const string &num2) {
    string sum = addStrings(num1, num2);
    int lenSum = sum.length();

    if (str.substr(start, lenSum) == sum) {
        if (start + lenSum == str.length()) return true;
        return isSumStringUtil(str, start + lenSum, num2, sum);
    }
    return false;
}

bool isSumString(const string &str) {
    int n = str.length();

    for (int len1 = 1; len1 <= n / 2; len1++) {
        for (int len2 = 1; len2 <= (n - len1) / 2; len2++) {
            string num1 = str.substr(0, len1);
            string num2 = str.substr(len1, len2);

            if (isSumStringUtil(str, len1 + len2, num1, num2)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    if (isSumString(str)) {
        cout << "The string is a sum-string." << endl;
    } else {    
        cout << "The string is not a sum-string." << endl;
    }

    return 0;
}
