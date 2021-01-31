/*************************************************************************
	> File Name: 剑指offer56.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 31 Jan 2021 03:45:41 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, c, a1, b1;
        for (int i = 0; i < nums.size(); i++) {
            c = nums[i];
            a1 = (a & ~b & ~c) | (~a & b & c);
            b1 = (~a & b & ~c) | (~a & ~b & c);
            a = a1;
            b = b1;
        }
        return b;
    }
};

int main() {
    return 0;
}
