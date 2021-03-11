/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/11 12:09 下午
 * @Description: https://leetcode.com/problems/longest-common-prefix/
 */

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *      Input: strs = ["flower","flow","flight"]
 *      Output: "fl"
 * Example 2:
 *      Input: strs = ["dog","racecar","car"]
 *      Output: ""
 *      Explanation: There is no common prefix among the input strings.
 * Constraints:
 *      0 <= strs.length <= 200
 *      0 <= strs[i].length <= 200
 *      strs[i] consists of only lower-case English letters.
 */
#include <vector>
#include <string>
#include "../utils.h"

using namespace std;

/**
 * 时间复杂度: O(nlog(n))
 * 空间复杂度: O(1)
 * 解题思路：
 *      先将数组排序，取开头和结尾，比较这两个字符串公共部分
 * @param strs
 * @return
 */
string longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    if (n == 0) return "";

    string ans = "";
    sort(begin(strs), end(strs));
    string a = strs.front();
    string b = strs.back();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            ans += a[i];
        } else {
            break;
        }
    }
    return ans;

}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    assert("fl" == longestCommonPrefix(strs));
    strs = {"dog", "racecar", "car"};
    assert(longestCommonPrefix(strs).empty());
    strs = {"flower", "flow", "flome"};
    assert("flo" == longestCommonPrefix(strs));
}
