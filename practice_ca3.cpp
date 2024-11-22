#include<bits/stdc++.h>
using namespace std;
        // Binomial coefficient
/*int binomial_coefficient(int n,int k){
    if(k==0 || k==n) return 1;
    return binomial_coefficient(n-1,k-1)+binomial_coefficient(n-1,k);
}
int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int res=binomial_coefficient(n,k);
    cout<<res<<endl;
}*/

        // Knapsack

/*int knapsack(vector<int> &a, vector<int> &b,int w,int v){
    vector<int> c(w+1,0);
    for(int i=0;i<=w;i++){
        for(int j=0;j<v;j++){
            if(a[j]<=i){
                c[i]=max(c[i],c[i-a[j]]+b[j]);
            }
        }
    }
    return c[w];
}
int main(){
    int n;
    cout<<"Enter number of items: ";
    cin>>n;

    vector<int> a(n),b(n);
    cout<<"Enter weights: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Enter values: ";
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    cout<<"Enter max value: ";
    int w;
    cin>>w;

    cout<<knapsack(a,b,w,n);
}
*/


        // edit distance

/*int edit_distance(string a,string b){
    int x=a.size();
    int y=b.size();
    vector<vector<int>> arr(x+1,vector<int>(y+1));
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0){
                arr[i][j]=j;
            }
            else if(j==0){
                arr[i][j]=i;
            }
            else if(arr[i-1]==arr[j-1]){
                arr[i][j]=arr[i-1][j-1];
            }
            else{
                arr[i][j]=1+min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]});
            }
        }
    }
    return arr[x][y];
}
int main(){
    string a;
    getline(cin,a);
    string b;
    getline(cin,b);
    cout<<edit_distance(a,b);
}
*/


            // Longest common subsequence

/*int length(vector<vector<int>> &arr,string a,string b){
    int x=a.length();
    int y=b.length();
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0||j==0){
                arr[i][j]=0;
            }
            else if(arr[i-1]==arr[j-1]){
                arr[i][j]=1+arr[i-1][j-1];
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[x][y];
}

string subsequence(vector<vector<int>> &arr,string a,string b){
    int x=a.length();
    int y=b.length();
    string lcs;
    int i=x;
    int j=y;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            lcs.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(arr[i-1][j]>arr[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}

int main(){
    string a;
    getline(cin,a);
    string b;
    getline(cin,b);
    vector<vector<int>> arr(a.length()+1,vector<int> (b.length()+1));
    cout<<"length: "<<length(arr,a,b);
    cout<<"subsequence: "<<subsequence(arr,a,b);
    return 0;
}
*/

            // partition subset

bool subset_sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0) return false;
    int t=sum/2;
    vector<bool> res(t+1,false);
    res[0]=true;
    for(int i=0;i<n;i++){
        for(int j=t;j>=i;j--){
            res[j]=res[j]||res[j-arr[i]];
        }
    }

    return res[t];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(subset_sum(arr,n)){
        cout<<"true";
    }
    else cout<<"false";
}