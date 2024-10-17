#include<bits/stdc++.h>
using namespace std;
bool happynumber(int n){
   unordered_set<int> seen;
   while(n!=1 && seen.find(n) == seen.end()){
    seen.insert(n); 
    int num=n;
    int digit=0;
    int res=0;
    while(num>0){
        digit=num%10;
        res+=digit*digit;
        num=num/10;
    }
    n=res;
   }
   return n==1;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(happynumber(n)){
        cout<<"It is a happy number";
    }
    else{
        cout<<"it is not a happy number";
    }
}