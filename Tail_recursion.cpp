#include<bits/stdc++.h>
using namespace std;
void print(int a){
    if(a<1){
        return;
    }
    else{
        cout<<a<<" ";
    }
    print(a/2);
}
int main(){
    print(100);
    return 0;
}