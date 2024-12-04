#include<bits/stdc++.h>
using namespace std;
/*bool ishappy(int n){
    unordered_set<int> seen;
    while(n!=1 && seen.find(n)==seen.end()){
        seen.insert(n);
        int dig=0;
        int res=0;
        while(n!=0){
            dig=n%10;
            res+=dig*dig;
            n=n/10;
        }
        n=res;
    }
    return n==1;
}
int main(){
    int n;
    cin>>n;
    if(ishappy(n)){
        cout<<"it is happy number";
    }
    else{
        cout<<"it is not a happy number";
    }
}
*/

// Way to tile
int findwaystotile(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return findwaystotile(n-1)+findwaystotile(n-2);
}
int main(){
    int n;
    cin>>n;
    int res=findwaystotile(n);
    cout<<res<<endl;
}