//
// Created by Administrator on 2021/1/21.
//
#include <iostream>

using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string result;
        result.append(s.substr(n, s.length()-1));
        result.append(s.substr(0, n));
        return result;
    }
};
/**
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
 * 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 * @return
 */
int main() {
    Solution solution;
    cout<<solution.reverseLeftWords("abcdefg", 2)<<endl;
    return 0;
}
