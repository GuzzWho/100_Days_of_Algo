#include <bits/stdc++.h>
using namespace std;

int find_next_greater(int n){
    string s = to_string(n);
    if (next_permutation(s.begin(), s.end())) {
        return stoi(s);
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << find_next_greater(n) << endl;
    return 0;
}
