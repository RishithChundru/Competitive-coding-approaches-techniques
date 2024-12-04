#include<bits/stdc++.h>
using namespace std;
// Fermat little theorem
/*
int main(){
    long long a,p;
    cin>>a;
    cin>>p;
    long long res=pow(a,p-1);
    cout<<res%p<<endl;
    if(res%p==1){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/

// Naive solution
/*bool isprime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}*/


// Efficient Solution
/*bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
        else return true;
    }
}
int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/


// best solution
/*bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/


// Full prime number
/*bool checkdigits(int n){
    while(n>0){
        int dig=n%10;
        if(dig!=2 && dig!=3 && dig!=5 && dig!=7) return false;
        n=n/10;
    }
    return true;
}
bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=2;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool isfullprime(int n){
    return checkdigits(n) && isprime(n);
}
int main(){
    int n;
    cin>>n;
    if(isfullprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/


// Fermat Factoring Method
int main(){
    int n;
    cin>>n;
    float x[n];
    for(int i=0;i*i<=n;i++){
        x[i]=sqrt(n+i*i);
        cout<<x[i]<<" ";
    }
}