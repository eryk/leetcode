/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/15 9:38
 * @Description: https://leetcode.com/problems/plus-one/
*/

/**
 * Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 *      Input: digits = [1,2,3]
 *      Output: [1,2,4]
 *      Explanation: The array represents the integer 123.
 * Example 2:
 *      Input: digits = [4,3,2,1]
 *      Output: [4,3,2,2]
 *      Explanation: The array represents the integer 4321.
 * Example 3:
 *      Input: digits = [0]
 *      Output: [1]
 * Constraints:
 *      1 <= digits.length <= 100
 *      0 <= digits[i] <= 9
 */
#include <vector>
#include "../utils.h"

using namespace std;

/**
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 * 解题思路：
 *      累加1，主要是要注意进位的问题，比如9、199这种情况，方法是从右开始加1，遇到需要进位的情况则下一轮循环也加1
 * @param digits
 * @return
 */
vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i] += 1;
            break;
        }
    }
    if (digits[0] == 0) digits.insert(digits.begin(),1);
    return digits;
}

int main() {
    vector<int> digits{1, 2, 3};
    vector<int> resp = plusOne(digits);
    printVector(resp);
    digits = {4, 3, 2, 2};
    resp = plusOne(digits);
    printVector(resp);
    digits = {0};
    resp = plusOne(digits);
    printVector(resp);
    digits = {4, 8, 9, 9};
    resp = plusOne(digits);
    printVector(resp);
    digits = {9};
    resp = plusOne(digits);
    printVector(resp);
}

