// Using Reecursion

#include<bits/stdc++.h>
using namespace std;
int count_tile(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return count_tile(n-1)+count_tile(n-2);
}
int main(){
    int size_of_board;
    cout<<"Enter size of board: ";
    cin>>size_of_board;
    int res=count_tile(size_of_board);
    cout<<res;
}
// Using Heap

/*void count_tile(int n){
    if(n==1){
        cout<<"1";
    }
    if(n==2){
        cout<<"2";
    }
    int a[n];
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int size_of_board;
    cout<<"Enter size of board: ";
    cin>>size_of_board;
    count_tile(size_of_board);
}*/