#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int least_prime[n+1]={0};
    least_prime[1]=1;
    for(int i=2;i<=n;i++){
        if(least_prime[i]==0){
            least_prime[i]=i;
        }
        for(int j=2*i;j<=n;j+=i){
            if(least_prime[j]==0){
                least_prime[j]=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << "Least prime factor of " << i << " is " << least_prime[i] << endl;
    }
}