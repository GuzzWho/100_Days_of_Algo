#include <bits/stdc++.h>
using namespace std;

int get_bit(uint32_t n, int i) {
    return (n & (1 << i)) != 0;
}

int set_bit(uint32_t n, int i) {
    return n | (1 << i);
}

int clear_bit(uint32_t n, int i) {
    return n & ~(1 << i);
}

int main(){
    uint32_t n = 0b1010;
    bitset<32> b(n);
    cout << b.to_string() << endl;

    cout << get_bit(n, 0) << endl;
    cout << get_bit(n, 1) << endl;
    cout << get_bit(n, 2) << endl;
    cout << get_bit(n, 3) << endl;
    cout << set_bit(n, 0) << endl;
    cout << clear_bit(n, 1) << endl;
    return 0;
}
