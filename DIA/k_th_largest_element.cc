#include <bits/stdc++.h>
using namespace std;

class Kth_Largest {
    public:
        int k;
        priority_queue<int, vector<int>, greater<int>> pq;
        Kth_Largest(int k, vector<int>& nums) {
            this->k = k;
            for (int num : nums) {
                add(num);
            }
        }

        int add(int val) {
            pq.push(val);
            if (pq.size() > k) {
                pq.pop();
            }
            return pq.top();
        }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    Kth_Largest* obj = new Kth_Largest(3, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}