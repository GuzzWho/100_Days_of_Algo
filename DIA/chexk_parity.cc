#include <bits/stdc++.h>
using namespace std;

int check_odd(int n){
    return n&1;
}

int main(){
    int n = 49;
    cout << check_odd(n)<< endl;
    return 0;
}