#include <bits/stdc++.h>
using namespace std;
void permute(vector<int> &arr, int index, vector<vector<int>> &result) {
    if (index == arr.size()) {
        result.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        permute(arr, index + 1, result);
        swap(arr[index], arr[i]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;

    permute(arr, 0, result);
    for (const auto &perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
