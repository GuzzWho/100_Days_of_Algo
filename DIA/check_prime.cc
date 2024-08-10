#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    // To check through all numbers of the form 6k ± 1
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << (isPrime(n) ? "Yes" : "No") << endl;
    return 0;
}


// It is based on the fact that all primes greater than 3 are of the form 6k ± 1,
// where k is any integer greater than 0. This is because all integers can be expressed as (6k + i), 
// where i = −1, 0, 1, 2, 3, or 4. And note that 2 divides (6k + 0), (6k + 2), and (6k + 4) and 3 divides (6k + 3). 
// So, a more efficient method is to test whether n is divisible by 2 or 3, 
// then to check through all numbers of the form 6k ± 1 <= √n. 
// This is 3 times faster than testing all numbers up to √n.
