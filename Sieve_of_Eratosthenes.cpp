#include<bits/stdc++.h>
using namespace std;
void sieveOfEratosthenes(int n){
    bool prime[n+1];
    for(int i=0;i<n;i++){
        prime[i]=true;
    }
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*2;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(prime[i]==true){
            cout<<i<<" ";
        }
    }
}
int main(){
    int n;
    cout<<"Enter value upto which you want the primes: ";
    cin>>n;
    sieveOfEratosthenes(n);
}