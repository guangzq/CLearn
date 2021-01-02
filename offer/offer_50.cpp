//
// Created by Administrator on 2021/1/2.
//
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,bool> map;
        for (char & i : s) {
            map[i] = map.find(i) == map.end();
        }
        for(char & i:s) {
            if (map[i]) return i;
        }
        return ' ';
    }
};
/**
 * 为啥全都是false
 * @return
 */
int main() {
    Solution solution;
    cout<<solution.firstUniqChar("abaccdeff")<<endl;
    return 0;
}
