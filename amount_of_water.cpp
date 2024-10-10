#include<bits/stdc++.h>
using namespace std;
int main(){
    int K,R,C;
    cout<<"Enter k litres: ";
    cin>>K;
    cout<<"Enter Row number(R): ";
    cin>>R;
    cout<<"Enter Column number(C): ";
    cin>>C;
    double arr[100][100] = {0};
    arr[0][0]=K;
    for(int i=0;i<100;i++){
        for(int j=0;j<=i;j++){
            if(arr[i][j]>1.0){
                double spare=arr[i][j]-1.0;
                arr[i][j]=1.0;
                arr[i+1][j]+=spare/2.0;
                arr[i+1][j+1]+=spare/2.0;
            }
        }
    }
    cout << "Water in glass at (" << R << ", " << C << ") is: " << arr[R][C] << " litres" << endl;

}