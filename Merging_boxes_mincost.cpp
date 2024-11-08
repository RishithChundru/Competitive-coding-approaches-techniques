/*
You are given N number of boxes. Each box contains a random number of chocolates. You can merge chocolates of two boxes in one empty box at a time. This process have to be repeated until all chocolates are merged into a single box.

The cost of merging two boxes is the summation of the number of chocolates in them.

You have to merge all boxes with a minimum cost.

Input Format

First line contains the number of chocolate boxes.

Second line contains N space seperated integers as number of chocolates in each box.

Constraints

1 < N < 1000,

1 < k < 100 (k= number of chocolates in each box)

Output Format

A single integer as a minimum cost of merging

Sample Input 0

4
12 34 23 21
Sample Output 0

179
Sample Input 1

6
2 8 6 4 3 9
Sample Output 1

78
Sample Input 2

7
3 5 7 2 1 9 8
Sample Output 2

90
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int> a(n);
    int res=0;
    int sum=0;
    for(int i=0;i<n-1;i++){
        res=arr[i]+arr[i+1];
        sum+=res;
        arr[i+1]=res;
        sort(arr.begin()+i+1,arr.end());
    }
    cout<<sum;
    
    return 0;
}
