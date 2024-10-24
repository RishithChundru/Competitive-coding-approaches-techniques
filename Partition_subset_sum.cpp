#include<bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[],int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    if(total%2!=0){
        return false;
    }
    int target=total/2;
    vector<bool> res(target + 1, false);
    res[0] = true;
    for(int i=0;i<n;i++){
        for(int j=target;j>=i;j--){
            res[j]=res[j]||res[j-arr[i]];
        }
    }
    return res[target];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(subset_sum(arr,n)){
        cout<<"true";
    }
    else cout<<"false";

}