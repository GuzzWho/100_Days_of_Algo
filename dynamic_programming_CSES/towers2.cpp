#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define MOD 1000000007

/* FUNCTIONS */
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { 
    cout << "{"; 
    for (auto x : v) cout << x << ","; 
    if (!v.empty()) cout << "\b"; // To handle empty vectors
    cout << "}";
}

/* UTILS */
ll gcd(ll a, ll b) { 
    if (b == 0) return a; 
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { 
    for (int i = 0; i < (int)a.size(); ++i) 
        if (a[i] >= 'a' && a[i] <= 'z') 
            a[i] -= 'a' - 'A'; 
    return a; 
}
string to_lower(string a) { 
    for (int i = 0; i < (int)a.size(); ++i) 
        if (a[i] >= 'A' && a[i] <= 'Z') 
            a[i] += 'a' - 'A'; 
    return a; 
}
bool prime(ll a) { 
    if (a <= 1) return false; 
    for (ll i = 2; i <= sqrt(a); ++i) 
        if (a % i == 0) return false; 
    return true; 
}

/*  All Required typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

/* Fast IO Initialization */
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/* Global Variables for DP */
const ll MAX_N = 10000000; // 10^7
vector<ll> dp0(MAX_N, 0); // dp[i][0]
vector<ll> dp1(MAX_N, 0); // dp[i][1]
vector<ll> answers;        // Precomputed answers

/* Function to Precompute DP Values */
void precompute() {
    if (MAX_N >= 1) {
        dp0[0] = 1;
        dp1[0] = 1;
        answers.pb((dp0[0] + dp1[0]) % MOD); // For n = 1
    }

    for (ll i = 1; i < MAX_N; i++) {
        dp0[i] = (dp0[i-1] * 4 + dp1[i-1]) % MOD;
        dp1[i] = (dp0[i-1] + dp1[i-1] * 2) % MOD;
        answers.pb((dp0[i] + dp1[i]) % MOD);
    }
}

/* Main Function */
int main()
{
    init();
    ll t, n;
    cin >> t;

    precompute(); // Precompute all DP values up to MAX_N

    while (t--)
    {
        cin >> n;
        if(n < 0){
            // Handle invalid input if necessary
            cout << "0\n";
            continue;
        }
        if(n == 0){
            // Based on your original solve function, n=0 corresponds to {1,1}, sum=2
            cout << "2\n";
            continue;
        }
        if(n > MAX_N){
            // If n exceeds precomputed range, handle accordingly
            // Here, we'll assume the answer is not precomputed
            // You can modify this based on problem constraints
            cout << "0\n";
            continue;
        }
        // Since n >=1 and n <= MAX_N
        cout << answers[n-1] << "\n";
    }
    return 0;
}
