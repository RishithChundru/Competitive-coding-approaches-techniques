#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    int left=0;
    for(int i=0;i<n;i++){
        left=left+arr[i];
        total-=arr[i];
        if(left>total){
            cout<<i;
            break;
        }
    }

}