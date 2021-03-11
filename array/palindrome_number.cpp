/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/11 9:40 上午
 * @Description: https://leetcode.com/problems/palindrome-number/
 */

/**
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
 *
 * Example 1:
 *      Input: x = 121
 *      Output: true
 * Example 2:
 *      Input: x = -121
 *      Output: false
 *      Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * Example 3:
 *      Input: x = 10
 *      Output: false
 *      Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * Example 4:
 *      Input: x = -101
 *      Output: false
 * Constraints:
 *      -2^31 <= x <= 2^31 - 1
 */

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      将int转为字符串，比较字符串与反转后的字符串是否想等
 * @param x
 * @return
 */
bool isPalindrome(int x) {
    if(x < 0) return false;
    string s1 = to_string(x);
    reverse(s1.begin(), s1.end());
    return to_string(x) == s1;
}

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      类似第7题，先将数字的右半部分反转，然后跟前半部分比较是否一致
 * @param x
 * @return
 */
bool isPalindrome1(int x){
    if(x<0 || (x!=0 &&x%10==0)) return false;
    int sum = 0;
    while(x > sum){
        sum = sum * 10 + x % 10;
        x = x / 10;
    }
    return (x==sum)||(x==sum/10); // 数字位数是偶数则比较 x == sum,如果是奇数则比较 x == sum / 10;
}

int main() {
    cout << isPalindrome1(-101) << endl;
    cout << isPalindrome1(121) << endl;
    cout << isPalindrome1(-121) << endl;
    cout << isPalindrome1(10) << endl;
    cout << isPalindrome1(123) << endl;
}