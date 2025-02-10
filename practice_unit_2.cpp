#include<bits/stdc++.h>
using namespace std;
// Fermat little theorem
/*
int main(){
    long long a,p;
    cin>>a;
    cin>>p;
    long long res=pow(a,p-1);
    cout<<res%p<<endl;
    if(res%p==1){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/

// Naive solution
/*bool isprime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}*/


// Efficient Solution
/*bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
        else return true;
    }
}
int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/


// best solution
/*bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/


// Full prime number
/*bool checkdigits(int n){
    while(n>0){
        int dig=n%10;
        if(dig!=2 && dig!=3 && dig!=5 && dig!=7) return false;
        n=n/10;
    }
    return true;
}
bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=2;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool isfullprime(int n){
    return checkdigits(n) && isprime(n);
}
int main(){
    int n;
    cin>>n;
    if(isfullprime(n)){
        cout<<"it is prime";
    }
    else{
        cout<<"it is not prime";
    }
}
*/


// Fermat Factoring Method
/*int main(){
    int n;
    cin>>n;
    float x[n];
    for(int i=0;i*i<=n;i++){
        x[i]=sqrt(n+i*i);
        cout<<x[i]<<" ";
    }
}
*/


// Sieve of eratosthenes - O(nloglogn)
/*void sieve(int n){
    bool res[n+1];
    for(int i=0;i<n;i++){
        res[i]=true;
    }
    for(int p=2;p*p<=n;p++){
        if(res[p]==true){
            for(int i=p*2;i<=n;i+=p){
                res[i]=false;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(res[i]==true){
            cout<<i<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    sieve(n);
}
*/



// Fermat's Factorization Method
/*void fermatFactor(int N) {
    if (N <= 0) {
        cout << "Number must be positive." << endl;
        return;
    }
    if (N % 2 == 0) { 
        cout << "Factors are: " << N / 2 << " and 2" << endl;
        return;
    }

    int x = ceil(sqrt(N));
    int y2, y;

    while (true) {
        y2 = x * x - N; 
        y = sqrt(y2);
        if (y * y == y2) { 
            break;
        }
        x++;
    }

    int factor1 = x - y;
    int factor2 = x + y;
    cout << "Factors are: " << factor1 << " and " << factor2 << endl;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    fermatFactor(N);
    return 0;
}
*/


// Segmented sieve

/* vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}
void segmentedSieve(int L, int R) {
    int limit = sqrt(R);
    vector<int> primes = simpleSieve(limit);
    vector<bool> isPrime(R - L + 1, true);

    // Marking multiples of primes found in step 1
    for (int p : primes) {
        // Find the minimum number in [L, R] that is a multiple of p
        int start = max(p * p, (L + p - 1) / p * p);

        for (int j = start; j <= R; j += p)
            isPrime[j - L] = false;
    }

    // Special case for L = 1, since 1 is not a prime number
    if (L == 1)
        isPrime[0] = false;

    // Output remaining primes in the range [L, R]
    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) {
            cout << (L + i) << " ";
        }
    }
    cout << endl;
}

int main() {
    int L, R;
    cout << "Enter the range [L, R]: ";
    cin >> L >> R;

    segmentedSieve(L, R);

    return 0;
}
*/


// Find all prime factors of a given number
/*void allprime(int n){
    if(n<=1) return;
    while(n%2==0){
        cout<<"2"<<" ";
        n=n/2;
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>2){
        cout<<n;
    }
}
int main(){
    int n;
    cin>>n;
    allprime(n);
}
*/


// Least prime factor upto n
/*void leastprimefactor(int n){
    vector<int> leastprime(n+1,0);
    leastprime[1]=1;
    for(int i=2;i<=n;i++){
        if(leastprime[i]==0){
            leastprime[i]=i;
            for(int j=i*i;j<=n;j+=i){
                if(leastprime[j]==0){
                    leastprime[j]=i;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"least prime factor of "<<i<<" is "<<leastprime[i]<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    leastprimefactor(n);
}
*/


// twin prime

/*void twinprime(int n){  
    if(n<2){
        cout<<"no twin prime exist"<<endl;
        return;
    }
    bool res[n+1];
    memset(res,true,sizeof(res));
    for(int p=2;p*p<=n;p++){
        if(res[p]==true){
            for(int i=p*2;i<=n;i+=p){
                res[i]=false;
            }
        }
    }   
    for(int i=2;i<=n-2;i++){
        if(res[i] && res[i+2]){
            cout<<i<<" "<<i+2<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    twinprime(n);
}
*/


// Twisted prime
/*bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(int i=5;i*i<=n;i=i+6){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int isreverse(int n){
    int rev=0;
    while(n!=0){
        rev=rev*10+n%10;
        n=n/10;
    }
    return rev;
}
bool istwistedpair(int n){
    if(isprime(n)==false) return false;
    return isprime(isreverse(n));
}
int main(){
    int n;
    cin>>n;
    if(istwistedpair(n)){
        cout<<"it is twisted pair";
    }
    else{
        cout<<"it is not twisted pair";
    }
}
*/


// Sieve of atkin
/*void sieveofatkin(int limit){
    if(limit>2) cout<< 2<<" ";
    if(limit>3) cout<< 3<<" ";
    bool res[limit];
    for(int i=0;i<limit;i++){
        res[i]=false;
    }
    for(int x=1;x*x<limit;x++){
        for(int y=1;y*y<limit;y++){
            int n=(4*x*x)+(y*y);
            if(n<=limit && ((n%12==1)||n%12==5)){
                res[n]^=true;
            }
            n=(3*x*x)+(y*y);
            if(n<=limit && n%12==7){
                res[n]^=true;
            }
            n=(3*x*x)-(y*y);
            if(x>y && n<=limit && n%12==11){
                res[n]^=true;
            }
        }
    }
    for(int r=5;r*r<limit;r++){
        if(res[r]){
            for(int i=r*r;i<limit;i+=r*r){
                res[i]=false;
            }
        }
    }
    for(int i=5;i<limit;i++){
        if(res[i]){
            cout<<i<<" ";
        }
    }
}
int main(){
    int limit;
    cin>>limit;
    sieveofatkin(limit);
}*/


// next prime palindrome
/*bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 ||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
bool ispalindrome(int n){
    int rev=0;
    int org=n;
    while(n!=0){
        rev=rev*10+n%10;
        n=n/10;
    }
    return org==rev;
}
int nextprimepal(int n){
    while(true){
        n++;
        if(ispalindrome(n) && isprime(n)){
            return n;
        }
    }
}
int main(){
    int n;
    cin>>n;
    cout<<nextprimepal(n);
}
*/

// Insert minimum number in array so that sum of array becomes prime
/*bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i++){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int minnumtoinsert(vector<int> &res){
    int sum=0;
    for(int num:res){
        sum+=num;
    }
    if(isprime(sum)) return 0;
    int numtoinsert=1;
    while(!isprime(sum+numtoinsert)){
        numtoinsert++;
    }
    return numtoinsert;
}
int main(){
    int n;
    cin>>n;
    vector<int> res(n);
    for(int i=0;i<n;i++){
        cin>>res[i];
    }
    int out=minnumtoinsert(res);
    if(out==0){
        cout<<"the sum is prime";
    }
    else{
        cout<<"the num to insert is "<<out<<endl;
    }
}
*/


// find prime pair with given sum
bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i++){
        if(n%i==0 && n%(i+2)==0){
            return false;
        }
    }
    return true;
}
void findpairwithsum(int sum){
    for(int i=2;i<=sum/2;i++){
        if(isprime(i) && isprime(sum-i)){
            cout<<"the pair is: "<<i<<" "<<sum-i;
            return;
        }
    }
    cout<<"no pair found for this sum";
}
int main(){
    int sum;
    cin>>sum;
    findpairwithsum(sum);
}