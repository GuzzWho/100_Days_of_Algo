#include <bits/stdc++.h>
using namespace std;

int count_digits(int n){
    return log10(n) + 1;
}

int main() {
    int n;
    cin >> n;
    cout << count_digits(n) << endl;
    return 0;
}