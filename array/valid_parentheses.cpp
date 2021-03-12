/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/12 13:24
 * @Description: https://leetcode.com/problems/valid-parentheses/
*/

/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *      1. Open brackets must be closed by the same type of brackets.
 *      2. Open brackets must be closed in the correct order.
 * Example 1:
 *      Input: s = "()"
 *      Output: true
 * Example 2:
 *      Input: s = "()[]{}"
 *      Output: true
 * Example 3:
 *      Input: s = "(]"
 *      Output: false
 * Example 4:
 *      Input: s = "([)]"
 *      Output: false
 * Example 5:
 *      Input: s = "{[]}"
 *      Output: true
 * Constraints:
 *      1 <= s.length <= 10^4
 *      s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      使用栈存储字符串，当遇到左括号，存入栈，遇到右括号，弹出栈并比较栈顶元素是否匹配
 * @param s
 * @return
 */
bool isValid(string s) {
    stack<char> result;
    for (char ch : s) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                result.push(ch);
                break;
            case ')': {
                if(result.empty() || result.top() != '(') return false;
                else result.pop();
                break;
            }
            case ']': {
                if(result.empty() || result.top() != '[') return false;
                else result.pop();
                break;
            }
            case '}': {
                if(result.empty() || result.top() != '{') return false;
                else result.pop();
                break;
            }
        }
    }
    return result.empty();
}

int main() {
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("([)]") << endl;
    cout << isValid("{[]}") << endl;
    cout << isValid("]") << endl;
    return 0;
}