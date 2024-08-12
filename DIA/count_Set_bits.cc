#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        bitset<32> b(n);
        cout << b.to_string() << endl;
        bitset<32> b1(n - 1);
        cout << b1.to_string() << endl;
        n = n & (n - 1);
        
        count++;
    }
    return count;
}

int main()
{
    int n = 49;
    cout << countSetBits(n) << endl;
    return 0;
}