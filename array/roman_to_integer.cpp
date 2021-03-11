/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/11 10:36 上午
 * @Description: https://leetcode.com/problems/roman-to-integer/
 */

/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII,
 * which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is written as IV.
 * Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *      I can be placed before V (5) and X (10) to make 4 and 9.
 *      X can be placed before L (50) and C (100) to make 40 and 90.
 *      C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Example 1:
 *      Input: s = "III"
 *      Output: 3
 * Example 2:
 *      Input: s = "IV"
 *      Output: 4
 * Example 3:
 *      Input: s = "IX"
 *      Output: 9
 * Example 4:
 *      Input: s = "LVIII"
 *      Output: 58
 *      Explanation: L = 50, V= 5, III = 3.
 * Example 5:
 *      Input: s = "MCMXCIV"
 *      Output: 1994
 *      Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * Constraints:
 *      1 <= s.length <= 15
 *      s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 *      It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      从字符右侧第二个字符开始循环，如果当前字符大于右侧字符，则累加，小于右侧字符，则相减
 * @param s
 * @return
 */
int romanToInt(string s) {
    if (s.empty()) return 0;

    unordered_map<char, int> T = {{'I', 1},
                                  {'V', 5},
                                  {'X', 10},
                                  {'L', 50},
                                  {'C', 100},
                                  {'D', 500},
                                  {'M', 1000}};

    int sum = T[s.back()];
    for (int i = s.length() - 2; i >= 0; i--) {
        if (T[s[i]] < T[s[i + 1]]) {
            sum -= T[s[i]];
        } else {
            sum += T[s[i]];
        }
    }
    return sum;
}

int main() {
    cout << romanToInt("III") << endl;
    cout << romanToInt("IV") << endl;
    cout << romanToInt("IX") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIV") << endl;
}