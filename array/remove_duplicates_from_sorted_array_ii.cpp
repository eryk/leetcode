/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2022/6/24 13:48
 * @Description:
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 */

/**
 * Given an integer array nums sorted in non-decreasing order, remove some
 * duplicates in-place such that each unique element appears at most twice. The
 * relative order of the elements should be kept the same. Since it is
 * impossible to change the length of the array in some languages, you must
 * instead have the result be placed in the first part of the array nums. More
 * formally, if there are k elements after removing the duplicates, then the
 * first k elements of nums should hold the final result. It does not matter
 * what you leave beyond the first k elements.
 *
 * Return k after placing the final result in the first k slots of nums.
 *
 * Do not allocate extra space for another array. You must do this by modifying
 * the input array in-place with O(1) extra memory. Clarification: Confused why
 * the returned value is an integer but your answer is an array? Note that the
 * input array is passed in by reference, which means a modification to the
 * input array will be known to the caller as well.
 *
 * Example 1:
 *      Input: nums = [1,1,1,2,2,3]
 *      Output: 5, nums = [1,1,2,2,3,_]
 *      Explanation: Your function should return k = 5, with the first five
 * elements of nums being 1, 1, 2, 2 and 3 respectively. It does not matter what
 * you leave beyond the returned k (hence they are underscores). Example 2:
 *      Input: nums = [0,0,1,1,1,1,2,3,3]
 *      Output: 7, nums = [0,0,1,1,2,3,3,_,_]
 *      Explanation: Your function should return k = 7, with the first seven
 * elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively. It does not
 * matter what you leave beyond the returned k (hence they are underscores).
 * Constraints:
 *      1 <= nums.length <= 3 * 10^4
 *      -10^4 <= nums[i] <= 10^4
 *      nums is sorted in non-decreasing order.
 */

#include <iostream>
#include <vector>

#include "../utils.h"

using namespace std;

class Solution {
public:
    /**
     * 时间复杂度 : O(n)
     * 空间复杂度 : O(1)
     * 解题思路：
     *      使用pos表示未重复或重复一次数据最新的位置，使用count记录当前数字的重复次数
     * @param nums
     * @return
     */
    int removeDuplicates1(vector<int> &nums) {
        if (nums.empty()) return 0;
        int pos = 1;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[pos++] = nums[i];
                count = 0;
            } else {
                if (count++ == 0) {
                    nums[pos++] = nums[i];
                }
            }
        }
        return pos;
    }

    /**
     * 时间复杂度 : O(n)
     * 空间复杂度 : O(1)
     * 解题思路：
     *      如果当前index和index-2不一致，则index+1
     * @param nums
     * @return
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) return nums.size();
        int index = 2;
        for (int i = 2; i < nums.size(); i++) {
            if(nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }

};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution solution;
    cout << solution.removeDuplicates(nums) << endl;
    printVector(nums);
    nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << solution.removeDuplicates(nums) << endl;
    printVector(nums);
    nums = {1, 1, 1};
    cout << solution.removeDuplicates(nums) << endl;
    printVector(nums);
}
