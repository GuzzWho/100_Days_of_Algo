#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define umii unordered_map<int, int>
#define usi unordered_set<int>
#define pq priority_queue


/* FUNCTIONS */
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

ll min(ll a, int b) { if (a < b) return a; return b; }
ll min(int a, ll b) { if (a < b) return a; return b; }
ll max(ll a, int b) { if (a > b) return a; return b; }
ll max(int a, ll b) { if (a > b) return a; return b; }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }
bool prime(ll a) { if (a == 1) return false; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

/* Main() function */
int main()
{
    init();
    
    // Start coding here
    ll n;
    cin >> n;
    vvc a(n, vector<char>(n));
    ll dp[n][n];
    for (ll i = 0; i < n; i++) 
    {
        for (ll j = 0; j < n; j++) 
        {
            cin >> a[i][j];
        }
    }

    if (a[0][0] == '*') 
    {
        cout << 0 << endl;
        return 0;
    }
    
    dp[0][0] = 1;
    for ( ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == 0 && j == 0) continue;
            dp[i][j] = 0;
            if (a[i][j] == '.')
            {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
                dp[i][j] %= MOD;                
            }
        }        
    }
     
     cout << dp[n-1][n-1] << endl;
    return 0;
}