#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &arr,int n,int k){
    // int count=0;
    // for (int i = 0; i < n; i++) {
    //     int currentSum = 0;

    //     for (int j = i; j < n; j++) {
    //         currentSum += arr[j];
            
    //         if (currentSum == k) {
    //             count++;
    //         }
    //     }
    // }
    // return count;
    unordered_map<int, int> m;
    int p=0;
    int count=0; 
    m[0]=1;
    for(int i=0;i<n;i++){
        p+=arr[i];
        int ab=p-k;
        count+=m[ab];
        m[p]++;
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter sum: ";
    cin>>k;
    int res=subarraySum(arr,n,k);
    cout<<res;
}