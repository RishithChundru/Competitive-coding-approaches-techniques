#include<bits/stdc++.h>
using namespace std;

// merge sort

/*void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> res;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            res.push_back(arr[left]);
            left++;
        }
        else{
            res.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        res.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        res.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=res[i-low];
    }
}
void mergesort(vector<int> &arr, int low,int high){
    if(low==high) return;
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
*/


// Quick sort
/*int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex=partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}
vector<int> quicksort(vector<int> &arr){
    qs(arr,0,arr.size()-1);
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr=quicksort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
*/


// Sorting Elements by Frequency
/*bool compare(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
vector<int> sortfreq(vector<int> &arr){
    unordered_map<int,int> freq;
    for(int num:arr){
        freq[num]++;
    }
    vector<pair<int,int>> b(freq.begin(),freq.end());
    sort(b.begin(),b.end(),compare);
    vector<int> res;
    for(auto &p:b){
        for(int i=0;i<p.second;i++){
            res.push_back(p.first);
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> res=sortfreq(arr);
    for(int num:res){
        cout<<num<<" ";
    }
    cout<<endl;
}
*/


// Finding Minimum Length Sorted Sub-array to Sort an Array
/*pair<int,int> minsortedsub(vector<int> &arr){
    int n=arr.size();
    int left=-1;
    int right=-1;
    int minseen=INT_MAX;
    int maxseen=INT_MIN;
    for(int i=0;i<n;i++){
        maxseen=max(maxseen,arr[i]);
        if(arr[i]<maxseen){
            right=i;
        }
    }
    for(int i=n-1;i>=0;i--){
        minseen=min(minseen,arr[i]);
        if(arr[i]>minseen){
            left=i;
        }
    }
    return {left,right};
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int> res=minsortedsub(arr);
    if(res.first==-1 && res.second==-1){
        cout<<"The array is sorted already";
    }
    else{
        cout<<"the minimum length required to sort an array is: "<<res.first<<" "<<res.second<<endl;
    }
}
*/


// sort binary string
/*int sortbinary(string num){
    int n=num.size();
    int count=0;
    char last='-';
    for(int i=0;i<n;i++){
        if(num[i]!=last){
            count++;
            last=num[i];
        }
    }
    return (count+1)/2;
}
int main(){
    string num;
    cin>>num;
    cout<<sortbinary(num);
}
*/


/// sort string lower and upper case
/*void sortstring(string a){
    vector<int> x;
    vector<int> y;
    int n=a.length();
    for(int i=0;i<n;i++){
        if(a[i]>='a' && a[i]<='z'){
            x.push_back(a[i]);
        }
        if(a[i]>='A' && a[i]<='Z'){
            y.push_back(a[i]);
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int i=0,j=0;
    for(int k=0;k<n;k++){
        if(a[k]>='a' && a[k]<='z'){
            a[k]=x[i];
            i++;
        }
        else{
            a[k]=y[j];
            j++;
        }
    }
    cout<<a;
}
int main(){
    string a;
    getline(cin,a);
    sortstring(a);
}
*/

// C++ Program to count all pairs with difference equal to k



int countpairs(vector<int> &arr, int K) {
    unordered_set<int> seen;  
    int count = 0;

    for (int num : arr) {
        if (seen.find(num + K) != seen.end()) {
            count++;
        }
        if (seen.find(num - K) != seen.end()) {
            count++;
        }
        seen.insert(num);  
    }

    return count;
}

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = countpairs(arr, K);
    cout << res << endl;
}
