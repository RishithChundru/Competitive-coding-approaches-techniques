#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int p;
    int a;
    cout<<"Enter only prime number(p): ";
    cin>>p;
    cout<<"Enter any positive number(a): ";
    cin>>a;
    long long int res=pow(a,p-1); //a^(p-1)==1(mod p)
    cout<<res%p<<endl;
    if(res%p==1){
        cout<<"it is prime";
    }
    else{
        cout<<"It is not prime";
    }
}

/*
#include <iostream>
using namespace std;

// Function to perform modular exponentiation
long long mod_exp(long long a, long long b, long long p) {
    long long result = 1;
    a = a % p;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % p;
        }
        b = b >> 1;
        a = (a * a) % p;
    }
    return result;
}

int main() {
    long long p, a;
    cout << "Enter only prime number (p): ";
    cin >> p;
    cout << "Enter any positive number (a): ";
    cin >> a;

    if (p <= 1) {
        cout << "It is not prime";
        return 0;
    }

    long long res = mod_exp(a, p - 1, p);

    if (res == 1) {
        cout << "It is prime";
    } else {
        cout << "It is not prime";
    }

    return 0;
}
*/