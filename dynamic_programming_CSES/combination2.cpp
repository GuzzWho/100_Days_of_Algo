#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

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
    // Analyse the difference between both combination1 and combination2
    // This requires ordering as inn removing duplicates, or repeating values
    ll n, sum;
    cin >> n >> sum;
    ll a[n];
    for (int i=0;i<n;i++) cin >> a[i];
    vll dp(sum+1, 0);
    for (int j=0;j<n;j++)
    {
        for (int i=1;i<=sum;i++) 
            {
                if (i-a[j] > 0) dp[i] = (dp[i] + dp[i-a[j]])%MOD;
                else if (i-a[j] == 0) dp[i] = (dp[i] + 1)%MOD;           
            }
    }
    cout << dp[sum]%MOD << endl;
    return 0;
    
}