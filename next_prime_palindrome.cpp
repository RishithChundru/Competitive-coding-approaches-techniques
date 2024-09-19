#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    bool isprime=true;
    if(n<=1) isprime=false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            isprime=false;
        }
    }
    if(isprime){
        cout<<"It is prime number"<<endl;
    }
    else{
        cout<<"it is not a prime number"<<endl;
    }
    int org=n;
    int rev=0;
    while(org!=0){
        rev=rev*10+org%10;
        org=org/10;
    }
    if(rev==n){
        cout<<"It is palindrome number"<<endl;
    }
    else{
        cout<<"it is not palindrome number"<<endl;
    }
}

// zero matrix column