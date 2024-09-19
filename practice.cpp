/*
#include<bits/stdc++.h>
using namespace std;
long int is_prime(int n,int a){
    long int org=n-1;
    long int b=pow(a,org);
    return b%n;
}
int main(){
    long int a,n;
    cout<<"Enter a prime number to check whether it is prime or not(n): ";
    cin>>n;
    cout<<"Enter any positive number: ";
    cin>>a;
    long int res=is_prime(n,a);
    if(res==1){
        cout<<"It is prime number";
    }
    else cout<<"It is not prime number";
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
static bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter prime number: ";
    cin>>n;
    bool res=isprime(n);
    if(res==1){
        cout<<"Prime!!";
    }
    else cout<<"Not Prime!!";
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
static bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter prime number: ";
    cin>>n;
    bool res=isprime(n);
    if(res==1){
        cout<<"Prime!!";
    }
    else cout<<"Not Prime!!";
}
*/
/*#include<bits/stdc++.h>
using namespace std;
static bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(int i=5;i*i<n;i=i+6){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter prime number: ";
    cin>>n;
    bool res=isprime(n);
    if(res==1){
        cout<<"Prime!!";
    }
    else cout<<"Not Prime!!";
}
*/

/*#include<bits/stdc++.h>
using namespace std;
static bool checkDigits(int n){
    while(n>0){
        int dig=n%10;
        if(dig!=2 && dig!=3 && dig!=5 && dig!=7) return false;
        n/=10;
    }
    return true;
}

static bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i*i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}

static bool isFullPrime(int n){
    return (checkDigits(n) && isPrime(n));
}
 
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if(isFullPrime(n)){
        cout<<"Yes"<<endl;
    }
    else cout<<"No";
}
*/

/*#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n) {
    bool prime[n+1];
    
    for (int i = 0; i < n; i++)
        prime[i] = true;
    
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (prime[i] == true)
            cout << i << " ";
    }
}

int main() {
    int n = 30; // Example value
    sieveOfEratosthenes(n);
    return 0;
}
*/

/*#include<bits/stdc++.h>
using namespace std;
void sieveOfEratosthenes(int n){
    bool prime[n+1];
    for(int i=0;i<n;i++){
        prime[i]=true;
    }
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*2;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==true){
            cout<<i<<" ";
        }
    }
}
int main(){
    int n;
    cout<<"Enter a number upto which you want prime numbers: ";
    cin>>n;
    sieveOfEratosthenes(n);
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    while(n%2==0){
        cout<<"2"<<" ";
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>2){
        cout<<n;
    }
}
*/
/*
// Least prime number
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    int least_prime[n+1] = {0};
    least_prime[1] = 1; 
    for (int i = 2; i <= n; i++) {
        if (least_prime[i] == 0) {
            least_prime[i] = i;
        }
        for (int j = 2 * i; j <= n; j += i) {
            if (least_prime[j] == 0) {
                least_prime[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << "Least prime factor of " << i << " is " << least_prime[i] << endl;
    }
    
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
void least_prime(int n,int least[]){
    least[1]=1;
    for(int i=2;i<=n;i++){
        if(least[i]==0){
            least[i]=i;
        }
        for(int j=2*i;j<=n;j+=i){
            if(least[j]==0){
                least[j]=i;
            }
        }
        
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int least[n+1]={0};
    least_prime(n,least);
    for (int i = 1; i <= n; i++) {
        cout << "Least prime factor of " << i << " is " << least[i] << endl;
    }
    int primeFactors[n+1];
    int i=0;
    while(n!=1){
        primeFactors[i]=least[n];
        i++;
        n=n/least[n];
    }
    cout << "Prime factors: ";
    for (int j = 0; j < i; j++) {
        cout << primeFactors[j] << " ";
    }
    cout << endl;

}
*/
/*#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to apply the Sieve of Eratosthenes to find all primes up to sqrt(R)
vector<int> simpleSieve(int limit) {
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

// Function to perform the segmented sieve
void segmentedSieve(int L, int R) {
    int limit = sqrt(R);
    vector<int> primes = simpleSieve(limit);

    // Boolean array to mark primes in range [L, R]
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

// Twin Prime
/*#include<bits/stdc++.h>
using namespace std;
void twinPrime(int n){
    if (n < 2) {
        cout << "No twin primes exist." << endl;
        return;
    }
    bool prime[n+1];
    memset(prime, true, sizeof(prime)); 
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*2;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int p=2;p<=n-2;p++){
        if(prime[p]&&prime[p+2]){
            cout << "(" << p << ", " << p + 2 << ") ";
        }
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    twinPrime(n);
}
*/

// Twisted prime
/*#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int reverseDigits(int n){
    int rev=0;
    while(n!=0){
        rev=rev*10+n%10;
        n=n/10;
    }
    return rev;
}
bool isTwistedPair(int n){
    if(!isprime(n)) return false;
    int reversed=reverseDigits(n);
    return isprime(reversed);
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(isTwistedPair(n)){
        cout<<n<<" is a twisted pair"<<endl;
    }
    else cout<<n<<" is not twisted pair";
}
*/

// sieve of atkin
// C++ program for implementation of Sieve of Atkin
/*#include <bits/stdc++.h>
using namespace std;
 
int SieveOfAtkin(int limit)
{
    // 2 and 3 are known to be prime
    if (limit > 2)
        cout << 2 << " ";
    if (limit > 3)
        cout << 3 << " ";
 
    // Initialise the sieve array with false values
    bool sieve[limit];
    for (int i = 0; i < limit; i++){
        sieve[i] = false;
    }
    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {
             
            // Main part of Sieve of Atkin
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
 
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;
 
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
 // Mark all multiples of squares as non-prime
    for (int r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i < limit; i += r * r)
                sieve[i] = false;
        }
    }
 
    // Print primes using sieve[]
    for (int a = 5; a < limit; a++)
        if (sieve[a])
            cout << a << " ";
}
 
// Driver program
int main()
{
    int limit = 30;
    SieveOfAtkin(limit);
    return 0;
}
*/
/*=
// Insert minimum number in array so that sum of array becomes prime
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n<1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 ||n%3==0) return false;;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int addMin(int n,int arr[]){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(isPrime(sum)){
        return 0;
    }
    int ext=1;
    while(!isPrime(sum+ext)){
        ext++;
    }
    return ext;
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=addMin(n,arr);
    cout<<"Minimum added to make sum prime: "<<res<<endl;
}
*/
/*\
// Find two prime numbers with given sum
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
void generatePrimes(bool primes[],int n){
    for(int i=0;i<=n;i++){
        primes[i]=true;
    }
    primes[0]=primes[1]=false;
    for(int p=2;p*p<=n;p++){
        if(primes[p]){
            for(int k=p*p;k<=n;k+=p){
                primes[k]=false;
            }
        }
    }
}
void findSum(int sum){
    bool primes[MAX];
    generatePrimes(primes,MAX);
    for(int i=2;i<=sum/2;i++){
        if(primes[i]&&primes[sum-i]){
            cout << "The two primes that sum up to " << sum << " are: " << i << " and " << sum - i << endl;
            return;
        }
    }
    cout<<"no such prime pair found";
}
int main(){
    int sum;
    cout<<"Enter sum: ";
    cin>>sum;
    findSum(sum);
}
*/

// pascal triangle
#include <iostream>
using namespace std;

// Function to generate and print Pascal's Triangle
void generatePascalTriangle(int numRows) {
    // Create a 2D array to hold the values of Pascal's Triangle
    int triangle[numRows][numRows];

    // Fill the triangle
    for (int i = 0; i < numRows; ++i) {
        // First and last elements of each row are 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        // Fill the inner elements
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Print Pascal's Triangle
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
