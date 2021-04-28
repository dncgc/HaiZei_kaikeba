/*************************************************************************
	> File Name: ali.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 28 Apr 2021 03:47:07 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int find_nth_element(vector<int> &nums, int k) {
    priority_queue<int> q;
    for (auto x : nums) {
        q.push(x);
        if (q.size() > k)
            q.pop();
    }
    //sort(nums.begin(), nums.end());
    //nth_element(nums.begin(), nums.begin() + k - 1, nums.end());
    //return nums[k - 1];
    return q.top();
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    cout << find_nth_element(nums, k) << endl;
    return 0;

}
