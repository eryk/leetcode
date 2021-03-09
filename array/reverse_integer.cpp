/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/9 11:45 上午
 * @Description: https://leetcode.com/problems/reverse-integer/
 */

/**
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 *
 * Example 1:
 *      Input: x = 123
 *      Output: 321
 * Example 2:
 *      Input: x = -123
 *      Output: -321
 * Example 3:
 *      Input: x = 120
 *      Output: 21
 * Example 4:
 *      Input: x = 0
 *      Output: 0
 * Constraints:
 *      -2^31 <= x <= 2^31 - 1
 */

#include <iostream>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      x%10 获取到最右边的数字，对这个数字乘以10，循环累加
 * @param x
 * @return
 */
int reverse(int x) {
    long res = 0;
    while (x != 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}

int reverse1(int x) {
    int res = 0;
    while (x != 0) {
        if ((res * 10l + x % 10l < INT_MIN) || (res * 10l + x % 10l > INT_MAX)){
            return 0;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    cout << reverse1(123) << endl;
    cout << reverse1(-123) << endl;
    cout << reverse1(120) << endl;
}


