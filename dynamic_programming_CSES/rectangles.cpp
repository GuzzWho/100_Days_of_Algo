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
#define vs vector<string>
#define vvc vector<vector<char>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define msi map<string, int>
#define mci map<char, int>
#define umii unordered_map<int, int>
#define usi unordered_set<int>
#define umsi unordered_map<string, int>
#define umci unordered_map<char, int>
#define pqi priority_queue<int>
#define pqpii priority_queue<pair<int, int>>
#define pqpll priority_queue<pair<long long, long long>>
#define pqvpii priority_queue<vector<pair<int, int>>>
#define pqvpll priority_queue<vector<pair<long long, long long>>>
#define pqvi priority_queue<vector<int>>
#define pqvll priority_queue<vector<long long>>
#define pqvvs priority_queue<vector<string>>
#define pqvs priority_queue<vector<string>>
#define pqvc priority_queue<vector<char>>
#define pqsi priority_queue<set<int>>
#define pqsc priority_queue<set<char>>
#define pqmsi priority_queue<map<string, int>>
#define pqmci priority_queue<map<char, int>>
#define pqumii priority_queue<unordered_map<int, int>>

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

ll solve(ll a, ll b) 
{
    vvll dp(a+1,vll(b+1,INT_MAX));
    for (ll i = 1; i <= a; i++)
    {
        for (ll j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (ll k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (ll k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    return dp[a][b];         
}
/* Main() function */
int main()
{
    init();
    
    // Start coding here
    ll a,b;
    cin >> a >> b;
    cout << solve(a,b) << endl;
    return 0;
}