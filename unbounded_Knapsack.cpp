#include<bits/stdc++.h>
using namespace std;
int knapsack(int a1[],int a2[],int w,int v){
    vector<int> a3(w + 1, 0);
    for(int i=0;i<=w;i++){
        for(int j=0;j<v;j++){
            if(a1[j]<=i){
                a3[i]=max(a3[i],a3[i-a1[j]]+a2[j]);
            }
        }
    }
    return a3[w];
}
int main(){
    int n;
    cout << "Enter number of items: ";
    cin >> n; 

    int a1[n], a2[n];
    cout<<"Enter weights: ";
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    cout<<"Enter values: ";
    for(int i=0;i<n;i++){
        cin>>a2[i];
    }
    int maxWeight;
    cout << "Enter maximum weight: ";
    cin >> maxWeight;

    cout << "Maximum value in Knapsack = " << knapsack(a1, a2, maxWeight, n) << endl;
    
}