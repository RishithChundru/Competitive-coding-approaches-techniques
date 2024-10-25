#include<bits/stdc++.h>
using namespace std;
int edit_distance(string a,string b){
    int x=a.size();
    int y=b.size();
    vector<vector<int>>ar(x+1,vector<int>(y+1));
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0){
                ar[i][j]=j;
            }
            else if(j==0){
                ar[i][j]=i;
            }
            else if(a[i-1]==b[j-1]){
                ar[i][j]=ar[i-1][j-1];
            }
            else{
                ar[i][j]=1+min({ar[i-1][j],ar[i][j-1],ar[i-1][j-1]});
            }
        }
    }
    return ar[x][y];
}
int main(){
    string a,b;
    cout<<"Enter string 1: ";
    getline(cin,a);
    cout<<"Enter string 2: ";
    getline(cin,b);
    cout<<edit_distance(a,b);
}