#include<bits/stdc++.h>
using namespace std;

// Happy Number

/*bool happynumber(int n){
    unordered_set<int> st;
    while(n!=1 && st.find(n)==st.end()){
        st.insert(n);
        int num=n;
        int rem=0;
        int res=0;
        while(num>0){
            rem=num%10;
            res+=rem*rem;
            num=num/10;
        }
        n=res;
    }
    return n==1;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(happynumber(n)){
        cout<<"it is happy number";
    }
    else{
        cout<<"it is not happy number";
    }
}
*/

// Subset_sum

/*void subsetsum(int index,vector<int> &ds,int arr[],int n,int sum,vector<int> &res){
    if(index==n){
        if(ds.size()==0){
            cout<<"0"<<" ";
        }
        else{
            res.push_back(sum);
        }
        return;
    }
    ds.push_back(arr[index]);
    subsetsum(index+1,ds,arr,n,sum+arr[index],res);
    ds.pop_back();
    subsetsum(index+1,ds,arr,n,sum,res);
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ds;
    vector<int> res;
    subsetsum(0,ds,arr,n,0,res);
    sort(res.begin(),res.end());
    for(int sum:res){
        cout<<sum<<" ";
    }
}*/

// water overflow

/*int main(){
    int k,r,c;
    cout<<"Enter k litres: ";
    cin>>k;
    cout<<"Enter row number: ";
    cin>>r;
    cout<<"Enter column number: ";
    cin>>c;

    double arr[100][100]={0};
    arr[0][0]=k;
    for(int i=0;i<99;i++){
        for(int j=0;j<=i;j++){
            if(arr[i][j]>1.0){
            double spare=arr[i][j]-1.0;
            arr[i][j]=1.0;
            arr[i+1][j]+=spare/2.0;
            arr[i+1][j+1]+=spare/2.0;
            }
        }
    }
    cout<<"water in glass at "<<r<<", "<<c<<" is: "<< arr[r-1][c-1];
}
*/

// Lexicographical order

/*void lorder(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    for(int j=0;j<=9;j++){
        if(10*i+j>n){
            return;
        }
        lorder(10*i+j,n);
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(int i=1;i<=9;i++){
        lorder(i,n);
    }

}
*/

// Partition
/*int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    int left=0;
    for(int i=0;i<n;i++){
        left+=arr[i];
        total-=arr[i];
        if(left>total){
            cout<<i;
            break;
        }
    }
}*/

// permutations

/*void permut(vector<int> &arr,int index, vector<vector<int>> &res){
    if(index==arr.size()){
        res.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        permut(arr,index+1,res);
        swap(arr[index],arr[i]);
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    vector<vector<int>> res;
    permut(arr,0,res);
    for(const auto &perm: res){
        for(int num: perm){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
*/

// knapsack

/*int knapsack(int a1[],int a2[],int w,int v){
    vector<int> a3(w+1,0);
    for(int i=0;i<=w;i++){
        for(int j=0;j<v;j++){
            if(a1[j]<=i){
                a3[i]=max(a3[i],a3[i-a1[j]+a2[j]]);
            }
        }
    }
    return a3[w];
}

int main(){
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    int a1[n],a2[n];
    cout<<"Enter weights: ";
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    cout<<"Enter values: ";
    for(int i=0;i<n;i++){
        cin>>a2[i];
    }
    int maxw;
    cout<<"Enter maximum weight: ";
    cin>>maxw;
    cout<<"maximum values: "<<knapsack(a1,a2,maxw,n);
}
*/

// Longest common sequence
/*
int lcs_length(vector<vector<int>> &arr, string a,string b){
    int x=a.length();
    int y=b.length();
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0||j==0){
                arr[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                arr[i][j]=1+arr[i-1][j-1];
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[x][y];
}
string lcs_seq(vector<vector<int>> &arr,string a,string b){
    string seq;
    int x=a.length();
    int y=b.length();
    int i=x,j=y;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            seq.push_back(a[i-1]);
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
    reverse(seq.begin(),seq.end());
    return seq;

}
int main(){
    string a,b;
    cout<<"Enter string1: ";
    getline(cin,a);
    cout<<"Enter string2: ";
    getline(cin,b);

    vector<vector<int>> arr(a.length()+1,vector<int>(b.length()+1));
    cout<<"length: "<<lcs_length(arr,a,b);
    cout<<"sequence: "<<lcs_seq(arr,a,b);
}
*/


// happy number
bool happynumber(int n){
    unordered_set<int> st;
    while(n!=1 && st.find(n)==st.end()){
        st.insert(n);
        int rem=0;
        int res=0;
        int num=n;
        while(num>0){
            rem=num%10;
            res+=rem*rem;
            num=num/10;
        }
        n=res;
    }
    return n==1;
}

int main(){
    int n;
    cin>>n;
    if(happynumber(n)){
        cout<<"yes";
    }
    else cout<<"no";
}