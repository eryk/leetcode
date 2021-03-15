/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/15 10:52
 * @Description: https://leetcode.com/problems/pascals-triangle/
*/

/**
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * Example 1:
 *      Input: numRows = 5
 *      Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 *      Input: numRows = 1
 *      Output: [[1]]
 * Constraints:
 *      1 <= numRows <= 30
 */

#include <vector>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(n)
 * 解题思路：
 *      从第二行开始，每行开头结尾赋值为1，其余每个元素使用上一行对应位置的2个元素相加
 * @param numRows
 * @return
 */
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    result[0] = vector<int>{1};
    for (int i = 1; i < numRows; i++) {
        result[i].resize(i + 1);
        result[i][0] = result[i][i] = 1;
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    return result;
}
