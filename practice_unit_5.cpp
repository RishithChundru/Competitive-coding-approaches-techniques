#include<bits/stdc++.h>
using namespace std;

// Binomial Coefficient
/*int bincoeff(int n,int k){
    if(k>n) return 0;
    if(k==0||k==n){
        return 1;   
    }
    return bincoeff(n-1,k-1)+bincoeff(n-1,k);
}
int main(){
    int n,k;
    cout<<"Enter total items: ";
    cin>>n;
    cout<<"Enter k items to select: ";
    cin>>k;
    int res=bincoeff(n,k);
    cout<<"Binomial Coeeficient is: "<<res<<endl;
}
*/


// Fibonacci series
// Recursion
/*int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}
*/


// Optimal Substructure property
// Floyd Warshall

/*const int INF = 1e9;  // Define a large value to represent infinity

void floydWarshall(int arr[][4], int n) {
    for (int k = 0; k < n; k++) {            // Intermediate node
        for (int i = 0; i < n; i++) {        // Source node
            for (int j = 0; j < n; j++) {    // Destination node
                if (arr[i][j] > arr[i][k] + arr[k][j] && arr[i][k] != INF && arr[k][j] != INF) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == INF)
                cout << "INF ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int n = 4;  // Define the size of the graph
    int arr[n][n] = {
        { 0, 5, INF, 10 },
        { INF, 0, 3, INF },
        { INF, INF, 0, 1 },
        { INF, INF, INF, 0 }
    };

    floydWarshall(arr, n);  // Call the function with the graph and size
    return 0;
}
*/


// Bellman ford
// C++ program to find single source shortest path Using Bellman
// -Ford algorithm

/*vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;
  
    for (int i = 0; i < V; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                
                if(i == V - 1)
                    return {-1};
               
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, 
                                 {1, 2, 1}, {0, 1, 5}};

    int src = 0;
    vector<int> ans = bellmanFord(V, edges, src);
    for (int dist : ans) 
        cout << dist << " ";
    return 0;
}
*/

// way to tile
/*int tile(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return tile(n-1)+tile(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<tile(n);
}
*/


// unbounded knapsack problem
/*int knapsack(int arr1[],int arr2[],int W,int v){
    vector<int> a3(W+1,0);
    for(int i=0;i<=W;i++){
        for(int j=0;j<v;j++){
            if(arr1[j]<=i){
                a3[i]=max(a3[i],a3[i-arr1[j]]+arr2[j]);
            }
        }
    }
    return a3[W];
}
int main(){
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    cout<<"Enter weights: ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    cout<<"Enter values: ";
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    int maxweight;
    cin>>maxweight;
    cout<<"maximum value in knapsack: "<<knapsack(arr1,arr2,maxweight,n);
}
*/


// Longest Increasing subsequence
/*int lenincseq(vector<int> &arr){
    int n=arr.size();
    vector<int> res(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                res[i]=max(res[i],res[j]+1);
            }
        }
    }
    return *max_element(res.begin(),res.end());
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lenincseq(arr);
}
*/


// longest Common Subsequence
/*int Lcs_length(vector<vector<int>> &arr,string a,string b){
    int x=a.length();
    int y=b.length();
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 || j==0){
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
string LCS(vector<vector<int>> &arr,string a,string b){
    int x=a.length();
    int y=b.length();
    string lcs;
    int i=x,j=y;
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
    string b;
    getline(cin,a);
    getline(cin,b);
    vector<vector<int>> arr(a.length()+1,vector<int>(b.length()+1));
    cout<<"Length of LCS is: "<<Lcs_length(arr,a,b)<<endl;
    cout<<"The string is: "<<LCS(arr,a,b);
}
*/


// partition subset sum
/*bool subset_sum(int arr[],int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    if(total%2!=0){
        return false;
    }
    int target=total/2;
    vector<bool> res(target+1,false);
    res[0]=true;
    for(int i=0;i<n;i++){
        for(int j=target;j>=arr[i];j--){
            res[j]=res[j]||res[j-arr[i]];
        }
    }
    return res[target];
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
    else{
        cout<<"false";
    }
}
*/


// Edit distance
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
            else if(a[i-1]==b[j-1]){
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
    string b;
    getline(cin,a);
    getline(cin,b);
    cout<<edit_distance(a,b);
}
*/


// pascal triangle
void generatePascalTriangle(int numRows) {
    int triangle[numRows][numRows];
    for (int i = 0; i < numRows; ++i) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows;

    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    if (numRows <= 0) {
        cout << "Number of rows must be positive." << endl;
        return 1;
    }

    generatePascalTriangle(numRows);

    return 0;
}
