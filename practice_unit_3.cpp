#include<bits/stdc++.h>
using namespace std;
/*bool ishappy(int n){
    //unordered_set<int> seen;
    while(n!=1){ // while(n!=1  && seen.find(n)==seen.end()){
       // seen.insert(n);
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
/*int findwaystotile(int n){
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
*/


// subset sum
/*void subset(int index,vector<int> &ds, int arr[],int n,int sum,vector<int> &result){
    if(index==n){
        if(ds.size()==0){
            cout<<"0"<<" ";
        }
        else{
            result.push_back(sum);
        }
        return;
    }
    ds.push_back(arr[index]);
    subset(index+1,ds,arr,n,sum+arr[index],result);
    ds.pop_back();
    subset(index+1,ds,arr,n,sum,result);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ds;
    vector<int> result;
    subset(0,ds,arr,n,0,result);
    sort(result.begin(),result.end());
    for(int num:result){
        cout<<num<<" ";
    }
}
*/


// lexigraphical order
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
    cin>>n;
    for(int i=1;i<=9;i++){
        lorder(i,n);
    }
    cout<<endl;
}
*/


// permutations
/*void permute(vector<int> &arr,int index,vector<vector<int>> &res){
    if(index==arr.size()){
        res.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        permute(arr,index+1,res);
        swap(arr[index],arr[i]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> res;
    permute(arr,0,res);
    for(const auto &perm:res){
        for(int num:perm){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
*/

// tail recursion
/*void tail(int n){
    if(n<1) return;
    else cout<<n<<" ";
    tail(n/2);
}
int main(){
    int a=100;
    tail(a);
}
*/


// without loop
/*void print(int a){
    while(a>=1){
        cout<<a<<" ";
        a=a/2;
    }
}
int main(){
    int a=10;
    print(a);
}

*/


// non tail recursion
/*int print(int a){
    if(a<1) return 0;
    else return 1+print(a/2);
}
int main(){
    int a;
    cin>>a;
    int x=print(a);
    cout<<x;
}*/


// water overflow
void overflow(int k,int r,int c){
    vector<vector<double>> res(r+1,vector<double>(r+1,0.0));
    res[0][0]=k;
    for(int i=0;i<r;i++){
        for(int j=0;j<=i;j++){
            if(res[i][j]>1.0){
                double spare=res[i][j]-1.0;
                res[i][j]=1.0;
                res[i+1][j]+=spare/2.0;
                res[i+1][j+1]+=spare/2.0;
            }
        }
    }
    cout<<res[r-1][c-1];
}
int main(){
    int k,r,c;
    cin>>k>>r>>c;
    overflow(k,r,c);
}