#include<bits/stdc++.h>
using namespace std;
void subsetSum(int index,vector<int> &ds,int arr[],int n,int sum,vector<int> &result){
    if(index==n){
         if(ds.size()==0){
            cout<<"0"<<" ";
        }
        else{
            result.push_back(sum);
        }
        return;
    }
    ds.push_back(arr[index]);
    subsetSum(index+1,ds,arr,n,sum+arr[index],result);
    ds.pop_back();
    subsetSum(index+1,ds,arr,n,sum,result);

}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ds;
    vector<int> result;
    subsetSum(0,ds,arr,n,0,result);
    sort(result.begin(),result.end());
    for(int sum:result){
        cout<<sum<<" ";
    }
}