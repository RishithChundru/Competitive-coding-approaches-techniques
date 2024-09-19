#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    float x[n];
    for(int i=0;i*i<n;i++){
        x[i]=sqrt(n+i*i);
        cout<<x[i]<<" ";
    }
}