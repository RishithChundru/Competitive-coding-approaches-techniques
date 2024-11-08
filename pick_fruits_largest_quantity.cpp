/*
You are given an integer array "fruits" denoting the number of fruits in various baskets. Every second, you have to do the following:

Choose the basket with the maximum number of fruits. If there is more than one basket with the maximum number of fruits, choose any. Leave behind the floor of the square root of the number of fruits in the basket. Take the rest of the fruits.

Return the number of fruits remaining after k seconds.

Input Format

First input would be the N(number of baskets). Second line contains N space seperated values. Third line contains k (number of seconds).

Constraints

0 < N < 1000000 ,0 < k < 100

Output Format

Output should be a value denoting the number of fruits remaining after k seconds

Sample Input 0

5
12 78 42 98 25
5
Sample Output 0

31
Sample Input 1

8
23 16 87 12 98 45 88 99
3
Sample Output 1

210
Sample Input 2

6
95 23 76 24 99 84
3
Sample Output 2

150
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;
    while (t--) {
        int max = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[max]) {
                max = i;
            }
        }
        int maxFruits = arr[max];
        int remaining = floor(sqrt(maxFruits));
        arr[max] = remaining;
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<sum;
    return 0;
}
