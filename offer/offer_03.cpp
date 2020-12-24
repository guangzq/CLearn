//
// Created by qiguang.zhu on 2020/12/23.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findRepeatNumber(vector<int> &nums) {
        int tmp;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums {0,2,3};
    int i = Solution::findRepeatNumber(nums);
    cout << "count " << i << endl;
    return 0;
}


