/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/20 17:51
 * @Description: https://leetcode.com/problems/pascals-triangle-ii/
 */

/**
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 * Example 1:
 *      Input: rowIndex = 3
 *      Output: [1,3,3,1]
 * Example 2:
 *      Input: rowIndex = 0
 *      Output: [1]
 * Example 3:
 *      Input: rowIndex = 1
 *      Output: [1,1]
 * Constraints:
 *      0 <= rowIndex <= 33
*/

#include <vector>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(n)
 * 解题思路：
 *      同118，https://leetcode.com/problems/pascals-triangle/
 * @param rowIndex
 * @return
 */
vector<int> getRow(int rowIndex) {
    vector<vector<int>> result(rowIndex + 1);
    result[0] = vector<int>{1};
    for (int i = 1; i < rowIndex + 1; i++) {
        result[i].resize(i + 1);
        result[i][0] = result[i][i] = 1;
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    return result.back();
}

int main() {

}