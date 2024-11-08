#include<bits/stdc++.h>
using namespace std;
void sortString(string a){
    vector<char> v1,v2;
    int n=a.length();
    for(int i=0;i<n;i++){
        if(a[i]>='a' && a[i]<='z'){
            v1.push_back(a[i]);
        }
        if(a[i]>='A' && a[i]<='Z'){
            v2.push_back(a[i]);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i=0,j=0;
    for(int k=0;k<n;k++){
        if(a[k]>='a' && a[k]<='z'){
            a[k]=v1[i];
            i++;
        }
        else{
            a[k]=v2[j];
            j++;
        }
    }
    cout<<a;

}
int main(){
    string a;
    cout<<"Enter a: ";
    getline(cin,a);
    sortString(a);
}