#include<bits/stdc++.h>
using namespace std;
int bincoeff(int n,int k){
    if(k>n) return 0;
    if(k==0||k==n){
        return 1;   
    }
    return bincoeff(n-1,k-1)+bincoeff(n-1,k);
}
int main(){
    int n,k;
    cout<<"Enter total items: ";
    cin>>n;
    cout<<"Enter k items to select: ";
    cin>>k;
    int res=bincoeff(n,k);
    cout<<"Binomial Coeeficient is: "<<res<<endl;
}