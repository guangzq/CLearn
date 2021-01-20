//
// Created by qiguang.zhu on 2021/1/20.
//
#include <iostream>

using namespace std;

/**
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 * 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
 * 输入: " hello world! "
    输出:"world! hello"
    解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

 * @return
 */
class Solution {
public:
    string reverseWords(string s) {
        int left = s.length() - 1;
        string result;
        while (left >= 0) {
            while (left >= 0 && s[left] == ' ') left--;
            if (left < 0) break;
            int right = left;
            while (left >= 0 && s[left] != ' ')left--;
            result.append(s.substr(left + 1, right - left));
            result.append(" ");
            right = left;
        }
        if (!result.empty()) result.pop_back();
        return result;
    }
};

int main() {
    Solution solution;
//    cout << solution.reverseWords(" hello world! ") << ']' << endl;
//    cout << solution.reverseWords(" I am a student. ") << ']' << endl;
    cout << solution.reverseWords("a good   example") << ']' << endl;
    return 0;
}
