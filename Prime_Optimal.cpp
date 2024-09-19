#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=15;
    bool res=false;
    if(n<=1) cout<<res;
    for(int i=2;i*i<n;i++){
        if(n%i==0) res=false;
        else res=true;
    }
    if(res){
        cout<<"It is prime";
    }
    else{
        cout<<"it is not prime";
    }
}