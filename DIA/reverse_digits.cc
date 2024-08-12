#include <bits/stdc++.h>
using namespace std;

int revere_digits(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main() {
    int n;
    cin >> n;
    cout << revere_digits(n) << endl;
    return 0;
}