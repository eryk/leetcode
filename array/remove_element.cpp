/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/12 16:10
 * @Description: https://leetcode.com/problems/remove-element/
*/

/**
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * Example 1:
 *      Input: nums = [3,2,2,3], val = 3
 *      Output: 2, nums = [2,2]
 *      Explanation: Your function should return length = 2, with the first two elements of nums being 2.
 *      It doesn't matter what you leave beyond the returned length. For example if you return 2 with nums = [2,2,3,3] or nums = [2,2,0,0], your answer will be accepted.
 * Example 2:
 *      Input: nums = [0,1,2,2,3,0,4,2], val = 2
 *      Output: 5, nums = [0,1,4,0,3]
 *      Explanation: Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
 *      Note that the order of those five elements can be arbitrary. It doesn't matter what values are set beyond the returned length.
 * Constraints:
 *      0 <= nums.length <= 100
 *      0 <= nums[i] <= 50
 *      0 <= val <= 100
*/

#include <iostream>
#include <vector>
#include "../utils.h"

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      pos标记当前需替换的位置，循环遍历不同于val的数字并赋值给pos位置的元素
 * @param nums
 * @param val
 * @return
 */
int removeElement(vector<int> &nums, int val) {
    if(nums.empty()) return 0;
    int pos = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[pos++] = nums[i];
        }
    }
    return pos;
}

int main() {
    vector<int> nums = {3,2,2,3};
    cout << removeElement(nums, 3) << endl;
    printVector(nums);
    nums = {0,1,2,2,3,0,4,2};
    cout << removeElement(nums, 2) << endl;
    printVector(nums);
}