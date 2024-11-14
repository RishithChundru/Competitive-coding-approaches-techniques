#include<bits/stdc++.h>
using namespace std;
void floyd(vector<vector<int>> &arr){
    int i,j,k;
    int n=arr.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(arr[i][j]>arr[i][k]+arr[k][j]){
                        arr[i][j]=arr[i][k]+arr[k][j];
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
      int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    cout << "Enter the adjacency matrix (use a large number, e.g., 1e9, for no direct path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    floyd(arr);
}