//
// Created by Administrator on 2021/1/6.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
    stack<int> stack;
    int start=0;
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        for (int i = 0; i < pushed.size(); ++i) {
            stack.push(pushed[i]);
            while (!stack.empty() && stack.top() == popped[start]) {
                stack.pop();
                start++;
            }
        }
        return stack.empty();
    }
};
int main() {
    Solution solution;
    vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2,9};
    bool va = solution.validateStackSequences(pushed,popped);
    cout<<va<<endl;
    return 0;
}
