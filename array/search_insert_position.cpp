/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/13 21:18
 * @Description: https://leetcode.com/problems/reverse-integer/
 */

/**
 * Given a sorted array of distinct integers and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * Example 1:
 *      Input: nums = [1,3,5,6], target = 5
 *      Output: 2
 * Example 2:
 *      Input: nums = [1,3,5,6], target = 2
 *      Output: 1
 * Example 3:
 *      Input: nums = [1,3,5,6], target = 7
 *      Output: 4
 * Example 4:
 *      Input: nums = [1,3,5,6], target = 0
 *      Output: 0
 * Example 5:
 *      Input: nums = [1], target = 0
 *      Output: 0
 * Constraints:
 *      1 <= nums.length <= 10^4
 *      -10^4 <= nums[i] <= 10^4
 *      nums contains distinct values sorted in ascending order.
 *      -10^4 <= target <= 10^4
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      循环比较每个元素找到插入位置
 * @param nums
 * @param target
 * @return
 */
int searchInsert1(vector<int> &nums, int target) {
    if(nums.empty()) return 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    if(nums.back() < target) return nums.size();
    return 0;
}

/**
 *
 * @param nums
 * @param target
 * @return
 */
int searchInsert2(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // (1) At this point, low > high. That is, low >= high+1
    // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
    // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
    //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
    return low;
}

int searchInsert(vector<int>& nums, int target) {
    vector<int>::iterator lower;
    //lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。也就是说，使用该函数在指定范围内查找某个目标值时，
    // 最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素。
    lower = lower_bound (nums.begin(), nums.end(), target);
    return (lower-nums.begin());
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 5) << endl;
    cout << searchInsert(nums, 2) << endl;
    cout << searchInsert(nums, 7) << endl;
    cout << searchInsert(nums, 0) << endl;
    nums = {1};
    cout << searchInsert(nums, 0) << endl;
}