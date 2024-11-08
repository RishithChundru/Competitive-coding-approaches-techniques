#include<bits/stdc++.h>
using namespace std;
int smallest_sub_length(int n, vector<int> &arr){
    if (n == 0) return -1;
    int start = 0;
    int end = n - 1;
    while (start < n - 1 && arr[start] <= arr[start + 1]) {
        start++;
    }
    if (start == n - 1) {
        return 0;
    }
    while (end > 0 && arr[end] >= arr[end - 1]) {
        end--;
    }
    int min_val=INT_MAX;
    int max_val=INT_MIN;
    for(int i=start;i<=end;i++){
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }
    while(start>0 && arr[start-1]>min_val){
        start--;
    }
    while(end<n-1 && arr[end+1]<max_val){
        end++;
    }
    return end-start+1;
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=smallest_sub_length(n,arr);
    cout<<"The smallest subarray length: "<<res;
}