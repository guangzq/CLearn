//
// Created by qiguang.zhu on 2020/12/30.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string str) {
        int length = str.size();
        int count = 0;
        for (char a: str) {
            if (a == ' ') {
                count++;
            }
        }
        str.resize(length + 2 * count);
        for (int i = length - 1, j = str.size() - 1; i < j; --i, --j) {
            if (str[i] != ' ') {
                str[j] = str[i];
            } else {
                str[j] = '0';
                str[j - 1] = '2';
                str[j - 2] = '%';
                j -= 2;
            }
        }
        return str;
    }
};

/**
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * 输入：s = "We are happy."
 * 输出："We%20are%20happy."
 * @return
 */
int main() {
    Solution solution;
    string result = solution.replaceSpace("We are happy too.");
    cout << result << endl;
}
